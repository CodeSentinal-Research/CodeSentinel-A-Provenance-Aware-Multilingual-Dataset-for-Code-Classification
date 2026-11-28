"""Temporal retrieval: from scattered frame hits to an ordered moment.

Ranking used to be a bag of frames: every hit a video produced was pooled, the
best one became the video's score, and the rest were a small bonus. That throws
away the one thing video has and a photo album does not  -  *time*. Two hits four
seconds apart are evidence of one moment; the same two hits twenty minutes apart
are two coincidences, and the old scoring could not tell them apart.

This module scores moments instead, in one pass:

1. ANN recall (HNSW) per variant      frame hits from the whole corpus
2. group by video                     a shortlist worth looking at closely
3. exact rescoring of those videos    (n_frames, n_steps), no ANN error
4. temporal clustering                runs of keyframes that belong together
5. sliding windows inside each run    a moment, not a frame
6. multi-query scoring per window     one score per query step
7. ordered alignment (DP)             steps in the order the user wrote them
8. ranked candidates                  with the winning span and timeline

Stage 3 is why stage 1 may be approximate: HNSW decides *which* videos to look
at, and every number that survives into the ranking is then recomputed exactly
against the video's own frame matrix.
"""
from __future__ import annotations

from collections import deque
from dataclasses import dataclass, field
from typing import Any, Iterable, Sequence

import numpy as np

from temporal_video_search.config import get_config
from temporal_video_search.store import FrameIndex


@dataclass
class Window:
    """One sliding window over a video's keyframes."""

    start: int  # first frame position (inclusive) in the video's frame list
    end: int  # last frame position (exclusive)
    start_time: float
    end_time: float
    #: score per query step, peak frame plus its supporting frames
    scores: np.ndarray
    #: position of the best frame for each step, in the video's frame list
    peaks: np.ndarray


@dataclass
class Timeline:
    """The best assignment of query steps to moments inside one video."""

    windows: list[int]  # window position per step
    peaks: list[int]  # frame position per step
    step_scores: list[float]
    ordered_mean: float
    unordered_mean: float
    #: how much the ordering constraint cost  -  0 when the best windows for the
    #: steps were already in the right order
    disorder: float
    score: float


def reduce_to_steps(scores: np.ndarray, owners: np.ndarray, n_steps: int) -> np.ndarray:
    """(n_frames, n_variants) -> (n_frames, n_steps), max over each step's variants.

    Max, not mean: one good caption match is the signal, and averaging in three
    mediocre paraphrases of the same step would bury it.
    """
    if scores.size == 0:
        return np.zeros((scores.shape[0], max(n_steps, 1)), dtype=np.float32)
    if n_steps <= 1 or owners.size == 0:
        return scores.max(axis=1, keepdims=True)
    reduced = np.full((scores.shape[0], n_steps), -np.inf, dtype=np.float32)
    for step in range(n_steps):
        columns = np.flatnonzero(owners == step)
        if columns.size:
            reduced[:, step] = scores[:, columns].max(axis=1)
    return np.where(np.isfinite(reduced), reduced, 0.0)


def cluster_runs(timestamps: list[float], max_gap_s: float) -> list[tuple[int, int]]:
    """Split a video's keyframes into runs separated by more than ``max_gap_s``.

    Keyframes are extracted on shot changes, so a long gap between two of them
    is a cut, not a pause: windows must never straddle one, or a window's
    "supporting frames" come from a different scene entirely.
    """
    if not timestamps:
        return []
    runs: list[tuple[int, int]] = []
    start = 0
    for position in range(1, len(timestamps)):
        if timestamps[position] - timestamps[position - 1] > max_gap_s:
            runs.append((start, position))
            start = position
    runs.append((start, len(timestamps)))
    return runs


def build_windows(
    timestamps: list[float],
    runs: Iterable[tuple[int, int]],
    window_s: float,
    stride_s: float,
) -> list[tuple[int, int]]:
    """Sliding windows, in seconds, that never cross a run boundary.

    Every run yields at least one window, so a one-frame shot is still
    reachable  -  it is exactly the kind of brief moment a Known-Item query is
    usually about.
    """
    windows: list[tuple[int, int]] = []
    for run_start, run_end in runs:
        if run_end <= run_start:
            continue
        position = run_start
        while position < run_end:
            limit = timestamps[position] + window_s
            end = position
            while end < run_end and timestamps[end] <= limit:
                end += 1
            end = max(end, position + 1)
            if not windows or windows[-1] != (position, end):
                windows.append((position, end))
            if end >= run_end:
                break
            # Advance by time, not by frame count: keyframe density varies
            # wildly between a talking head and a montage.
            target = timestamps[position] + stride_s
            nxt = position + 1
            while nxt < run_end and timestamps[nxt] < target:
                nxt += 1
            position = nxt
    return windows


def score_windows(
    step_scores: np.ndarray,
    timestamps: list[float],
    spans: list[tuple[int, int]],
    support: int,
    support_weight: float,
) -> list[Window]:
    """Score each window per step: its peak frame plus its supporting frames.

    A window whose whole span looks like the query beats a window with one lucky
    frame and nothing around it, which is what the support term buys.
    """
    windows: list[Window] = []
    for start, end in spans:
        block = step_scores[start:end]  # (n_frames_in_window, n_steps)
        if block.size == 0:
            continue
        peaks = block.argmax(axis=0)
        best = block.max(axis=0)
        if support > 0 and block.shape[0] > 1:
            # Partition rather than sort: only the top `support` matter.
            take = min(support + 1, block.shape[0])
            top = -np.partition(-block, take - 1, axis=0)[:take]
            # Drop the peak itself so support measures the *rest* of the window.
            rest = top[1:]
            supporting = rest.mean(axis=0) if rest.size else np.zeros_like(best)
            filled = min(rest.shape[0], support) / max(support, 1)
        else:
            supporting = np.zeros_like(best)
            filled = 0.0
        scores = best + support_weight * supporting * filled
        windows.append(
            Window(
                start=start,
                end=end,
                start_time=float(timestamps[start]),
                end_time=float(timestamps[end - 1]),
                scores=scores.astype(np.float32),
                peaks=(peaks + start).astype(np.int64),
            )
        )
    return windows


def align_steps(
    scores: np.ndarray,
    times: Sequence[float] | None = None,
    max_gap: float | None = None,
) -> tuple[list[int], float]:
    """Best strictly-increasing assignment of positions to steps.

    ``scores`` is (n_positions, n_steps) in temporal order. Returns the chosen
    positions (one per step, strictly increasing) and their total score.

    Picking each step's best position independently returns them out of order,
    because the steps of one procedure look alike; this maximises the total
    subject to the ordering, exactly, in O(n-k).

    With ``times`` and ``max_gap``, consecutive steps must also land within
    ``max_gap`` seconds of each other  -  "then" means soon after, and without the
    bound the DP cheerfully pairs a shot with another twelve minutes later.
    """
    n_positions, n_steps = scores.shape
    if n_steps == 0 or n_positions == 0:
        return [], 0.0
    if n_positions < n_steps:
        # Not enough distinct positions to keep the ordering strict: spread the
        # steps over what exists rather than failing outright. The same fallback
        # catches a `max_gap` so tight that no ordered assignment exists at all.
        positions = [
            min(n_positions - 1, round(i * (n_positions - 1) / max(n_steps - 1, 1)))
            for i in range(n_steps)
        ]
        return positions, float(sum(scores[p, e] for e, p in enumerate(positions)))

    order = np.arange(n_positions)
    dp = np.full((n_steps, n_positions), -np.inf, dtype=np.float64)
    back = np.full((n_steps, n_positions), -1, dtype=np.int64)
    dp[0] = scores[:, 0]

    bounded = times is not None and max_gap is not None and max_gap > 0
    for step in range(1, n_steps):
        previous = dp[step - 1]
        if bounded:
            best_before, arg_before = _bounded_best_before(previous, times, float(max_gap))
        else:
            running_max = np.maximum.accumulate(previous)
            running_arg = np.maximum.accumulate(np.where(previous >= running_max, order, 0))
            # Shift by one: this step must land strictly after the previous one.
            best_before = np.concatenate(([-np.inf], running_max[:-1]))
            arg_before = np.concatenate(([-1], running_arg[:-1]))
        dp[step] = scores[:, step] + best_before
        back[step] = arg_before

    last = int(np.argmax(dp[n_steps - 1]))
    if not np.isfinite(dp[n_steps - 1, last]):
        positions = [
            min(n_positions - 1, round(i * (n_positions - 1) / max(n_steps - 1, 1)))
            for i in range(n_steps)
        ]
        return positions, float(sum(scores[p, e] for e, p in enumerate(positions)))

    total = float(dp[n_steps - 1, last])
    positions = [0] * n_steps
    cursor = last
    for step in range(n_steps - 1, -1, -1):
        positions[step] = int(cursor)
        cursor = int(back[step, cursor])
        if cursor < 0 and step > 0:
            cursor = max(0, positions[step] - 1)
    return positions, total


def _bounded_best_before(
    previous: np.ndarray, times: Sequence[float], max_gap: float
) -> tuple[np.ndarray, np.ndarray]:
    """Best earlier state within ``max_gap`` seconds, for every position.

    A monotonic deque keeps this O(n) rather than O(n^2): each position enters
    and leaves the window once, so the whole alignment stays linear even on a
    long video with hundreds of windows.
    """
    n = len(previous)
    best = np.full(n, -np.inf, dtype=np.float64)
    argument = np.full(n, -1, dtype=np.int64)
    queue: deque[int] = deque()  # positions, decreasing by dp value
    for position in range(1, n):
        candidate = position - 1
        while queue and previous[queue[-1]] <= previous[candidate]:
            queue.pop()
        queue.append(candidate)
        # Drop states too far in the past for this position to follow.
        while queue and times[position] - times[queue[0]] > max_gap:
            queue.popleft()
        if queue and np.isfinite(previous[queue[0]]):
            best[position] = previous[queue[0]]
            argument[position] = queue[0]
    return best, argument


def best_timeline(
    windows: list[Window],
    step_scores: np.ndarray,
    order_weight: float,
    max_gap_s: float | None = None,
) -> Timeline | None:
    """Pick one window per step, in order, and score the result.

    A single-step query is the common case and collapses to "the best window".
    For several steps the ordered assignment is compared against the free one:
    the gap between them is how much the video had to be read out of order, and
    ``order_weight`` decides how much that costs. A video that shows the steps
    in the wrong sequence is not the video the user is describing.
    """
    if not windows:
        return None
    matrix = np.stack([w.scores for w in windows])  # (n_windows, n_steps)
    n_steps = matrix.shape[1]

    if n_steps == 1:
        best = int(matrix[:, 0].argmax())
        value = float(matrix[best, 0])
        return Timeline(
            windows=[best],
            peaks=[int(windows[best].peaks[0])],
            step_scores=[value],
            ordered_mean=value,
            unordered_mean=value,
            disorder=0.0,
            score=value,
        )

    positions, total = align_steps(
        matrix, times=[w.start_time for w in windows], max_gap=max_gap_s
    )
    ordered_mean = total / n_steps
    unordered_mean = float(matrix.max(axis=0).mean())
    disorder = max(0.0, unordered_mean - ordered_mean)
    chosen = [float(matrix[p, step]) for step, p in enumerate(positions)]
    # Half mean, half weakest step: a sequence is only as good as the step it
    # matched worst, and the mean alone lets one strong step carry a missing one.
    aggregate = 0.5 * ordered_mean + 0.5 * min(chosen)
    return Timeline(
        windows=positions,
        peaks=_distinct_peaks(windows, step_scores, positions),
        step_scores=chosen,
        ordered_mean=ordered_mean,
        unordered_mean=unordered_mean,
        disorder=disorder,
        score=aggregate - order_weight * disorder,
    )


def _distinct_peaks(
    windows: list[Window], step_scores: np.ndarray, positions: list[int]
) -> list[int]:
    """One frame per step, strictly advancing through the video.

    Windows overlap, so two consecutive steps can pick the same peak frame and
    the answer then shows the same picture twice for "X, then Y". Each step gets
    the best frame *after* the previous step's, inside its own window.
    """
    peaks: list[int] = []
    previous = -1
    for step, window_position in enumerate(positions):
        window = windows[window_position]
        low = max(window.start, previous + 1)
        if low < window.end:
            pick = low + int(step_scores[low : window.end, step].argmax())
        else:
            # The window lies entirely before the previous step's frame: keep
            # its own peak rather than inventing a frame outside the window.
            pick = int(window.peaks[step])
        peaks.append(pick)
        previous = max(previous, pick)
    return peaks


@dataclass
class TemporalMatch:
    """One video's best moment for the whole query."""

    video_id: str
    score: float
    timeline: Timeline
    windows: list[Window]
    #: frame metadata rows of the video, in temporal order
    meta: list[dict[str, Any]] = field(default_factory=list)

    @property
    def best_position(self) -> int:
        return self.timeline.peaks[0]

    def span(self) -> tuple[float, float]:
        first = self.windows[self.timeline.windows[0]]
        last = self.windows[self.timeline.windows[-1]]
        return first.start_time, last.end_time


def shortlist_videos(
    frame_scores: dict[int, dict[str, Any]],
    limit: int,
) -> list[str]:
    """Videos worth exact rescoring, best ANN evidence first.

    Ranked on the best hit plus a small term for how many hits the video got:
    at this stage the question is only "is there something here", and one frame
    is weaker evidence than five.
    """
    grouped: dict[str, tuple[float, int]] = {}
    for hit in frame_scores.values():
        video_id = str(hit["video_id"])
        best, count = grouped.get(video_id, (-1e9, 0))
        grouped[video_id] = (max(best, float(hit["score"])), count + 1)
    ranked = sorted(
        grouped.items(),
        key=lambda item: item[1][0] + 0.01 * min(item[1][1], 10),
        reverse=True,
    )
    return [video_id for video_id, _ in ranked[:limit]]


def match_video(
    index: FrameIndex,
    video_id: str,
    vectors: np.ndarray,
    owners: np.ndarray,
    n_steps: int,
) -> TemporalMatch | None:
    """Stages 3-7 for one video: exact rescoring through to an ordered timeline."""
    from temporal_video_search.retrieval import score_video_frames

    cfg = get_config()
    raw, meta = score_video_frames(index, video_id, vectors)
    if raw.shape[0] == 0 or not meta:
        return None

    step_scores = reduce_to_steps(raw, owners, n_steps)
    timestamps = [float(row["timestamp"]) for row in meta]
    spans = build_windows(
        timestamps,
        cluster_runs(timestamps, cfg.cluster_gap_s),
        cfg.window_s,
        cfg.window_stride_s,
    )
    windows = score_windows(
        step_scores,
        timestamps,
        spans,
        support=cfg.window_support,
        support_weight=cfg.window_support_weight,
    )
    timeline = best_timeline(
        windows, step_scores, cfg.order_weight, max_gap_s=cfg.max_step_gap_s
    )
    if timeline is None:
        return None
    return TemporalMatch(
        video_id=video_id,
        score=timeline.score,
        timeline=timeline,
        windows=windows,
        meta=meta,
    )
