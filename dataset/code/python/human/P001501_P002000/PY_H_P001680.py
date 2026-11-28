"""Elite-archive survey over the two-dimensional chart (MAP-Elites).

The archive maps each niche of the barycentric chart to the best tree found
there.  A survey selects an occupied niche, varies its elite with one tree move,
evaluates the offspring, and stores it when the offspring niche is empty or when
the offspring beats the incumbent.  The elite log-likelihood is the map
elevation.  There is no bias potential, no temperature, and no acceptance ratio.

Ref: mouret2015mapelites (illumination by mapping elites).
"""
from __future__ import annotations

import math
from dataclasses import dataclass, field

import numpy as np

from hifuku.anchor_triangle import AnchorTriangle, barycentric
from hifuku.constants import (
    ARCHIVE_BATCH,
    ARCHIVE_CELL,
    ARCHIVE_COVERAGE_EPS,
    ARCHIVE_GATE_WINDOW,
    ARCHIVE_LOGL_MARGIN,
    ARCHIVE_N_ITERS,
    ARCHIVE_PRECISION_EPS,
    DEFAULT_SCALE_WIDTH,
    DEFAULT_SIGMA_SLIDE,
    P_MOVE_NNI,
    P_MOVE_SLIDE,
    P_MOVE_SPR,
)
from hifuku.backend import RunContext
from hifuku.driver import ArchiveResult
from hifuku.moves import (
    branch_scale_move,
    branch_slide_move,
    nni_move,
    spr_move,
)
from hifuku.pruning import log_likelihood
from hifuku.taxa import TaxonTable
from hifuku.tree_io import HifukuTree


def _set_global_leaf_indices(tree: HifukuTree, taxon_table: TaxonTable) -> None:
    """Set global_leaf_indices on the tree in place, keyed by the taxon table."""
    glidx = np.full(tree.n_nodes, -1, dtype=np.int32)
    for i in range(tree.n_leaves):
        glidx[i] = taxon_table.index_of(tree.names[i])
    tree.global_leaf_indices = glidx


@dataclass
class Elite:
    """The best tree found in one niche.  ``z`` is the out-of-plane residual.

    ``tree`` is None for an elite loaded from disk until its niche is touched;
    see ``EliteArchive.tree_at``.
    """

    logL: float
    tree: "HifukuTree | None"
    z: float


@dataclass
class EliteArchive:
    """A map from niche to elite over an unbounded 2D chart grid.

    A niche is a square cell of side ``cell``, indexed by integer coordinates
    ``(i, j)`` from ``origin``.  The grid has no window: any chart point has a
    niche.  Exploration is bounded by the log-likelihood gate in the survey, not
    by the grid, and the filled niches form the map's footprint.

    ``anchors`` (an ``AnchorTriangle``), ``taxon_table``, and ``metric`` hold the
    context the archive was built against.  The accessors fall back to ``anchors``
    when their argument is omitted.  :meth:`locate` uses all three to place a new
    tree in the same frame as the map.  A later re-anchoring step can use the
    anchors to stitch archives on different anchor planes into one frame.
    """

    cell: float = ARCHIVE_CELL
    origin: float = 0.0
    anchors: object = field(default=None, repr=False)      # the AnchorTriangle used
    taxon_table: object = field(default=None, repr=False)  # namespace for locate()
    metric: object = field(default=None, repr=False)       # tree metric used
    tree_source: object = field(default=None, repr=False)   # dict (i,j) -> newick, for loaded archives
    elites: dict = field(default_factory=dict)   # (i, j) -> Elite
    keys: list = field(default_factory=list)     # occupied niches, insertion order

    @property
    def n_filled(self) -> int:
        return len(self.elites)

    def tree_at(self, key):
        """Return the elite tree at niche ``key``, parsing its stored newick on
        first access.  For a live archive the tree is already present; for a
        loaded archive it is materialized from ``tree_source`` and cached."""
        elite = self.elites[key]
        if elite.tree is not None:
            return elite.tree
        if self.tree_source is None or key not in self.tree_source:
            raise KeyError(f"no tree available for niche {key}")
        from hifuku.tree_io import read_tree
        t = read_tree(self.tree_source[key], self.taxon_table, from_string=True)
        _set_global_leaf_indices(t, self.taxon_table)
        elite.tree = t
        return t

    def trees(self):
        """Iterate ``((i, j), HifukuTree)`` over all elites, parsing lazily."""
        for key in self.keys:
            yield key, self.tree_at(key)

    def niche_of(self, lam1: float, lam2: float):
        """Return the ``(i, j)`` niche of a chart point.  Unbounded: never None."""
        i = int(np.floor((lam1 - self.origin) / self.cell))
        j = int(np.floor((lam2 - self.origin) / self.cell))
        return (i, j)

    def niche_center(self, key):
        """Chart coordinates ``(lam1, lam2)`` of a niche's center."""
        i, j = key
        return (self.origin + (i + 0.5) * self.cell,
                self.origin + (j + 0.5) * self.cell)

    def place(self, key, elite: Elite) -> bool:
        """Store the elite when its niche is empty or the elite is better."""
        cur = self.elites.get(key)
        if cur is None:
            self.elites[key] = elite
            self.keys.append(key)
            return True
        if elite.logL > cur.logL:
            self.elites[key] = elite
            return True
        return False

    def place_batch(self, items) -> tuple:
        """Merge a batch of candidates and return ``(n_new, gain)``.

        ``items`` is a sequence of ``(key, Elite)``.  The method reduces the
        batch to one winner per niche, then compares each winner against the
        incumbent.  ``n_new`` counts the niches that were empty.  ``gain`` sums
        the improvement of each winner over its incumbent.  A new niche adds no
        gain.

        The tie rules follow the device place in ``gpu_archive``, which packs a
        fitness in the high bits and a slot index in the low bits, then takes an
        atomic maximum.  The incumbent holds the largest slot, so it wins a tie
        against a candidate.  Among candidates of equal fitness, the last one
        wins.

        One call with one candidate gives the same result as :meth:`place`, so
        a one-walker run reproduces a sequential run.
        """
        winners: dict = {}
        for key, elite in items:
            best = winners.get(key)
            if best is None or elite.logL >= best.logL:
                winners[key] = elite

        n_new, gain = 0, 0.0
        for key, elite in winners.items():
            cur = self.elites.get(key)
            if cur is None:
                self.elites[key] = elite
                self.keys.append(key)
                n_new += 1
            elif elite.logL > cur.logL:
                gain += elite.logL - cur.logL
                self.elites[key] = elite
        return n_new, gain

    def best_logL(self) -> float:
        """The largest finite log-likelihood held, or -inf if none is.

        Non-finite values are skipped rather than compared.  ``max`` keeps the
        first item a comparison cannot beat, so a NaN in the sequence returns
        either itself or its neighbor depending on where it sits, which would
        make the answer a function of insertion order.
        """
        return max((e.logL for e in self.elites.values() if math.isfinite(e.logL)),
                   default=float("-inf"))

    def index_bounds(self):
        """``(i_min, i_max, j_min, j_max)`` over filled niches, or None if empty."""
        if not self.elites:
            return None
        iis = [k[0] for k in self.elites]
        jjs = [k[1] for k in self.elites]
        return (min(iis), max(iis), min(jjs), max(jjs))

    def filled_bounds(self):
        """Chart bounding box ``(lam1_lo, lam1_hi, lam2_lo, lam2_hi)`` of the
        filled niches, or None if empty."""
        b = self.index_bounds()
        if b is None:
            return None
        i0, i1, j0, j1 = b
        return (self.origin + i0 * self.cell, self.origin + (i1 + 1) * self.cell,
                self.origin + j0 * self.cell, self.origin + (j1 + 1) * self.cell)

    def elevation_grid(self) -> np.ma.MaskedArray:
        """Elite log-likelihood over the filled bounding box, a masked array."""
        b = self.index_bounds()
        if b is None:
            return np.ma.masked_all((1, 1))
        i0, i1, j0, j1 = b
        g = np.full((i1 - i0 + 1, j1 - j0 + 1), np.nan)
        for (i, j), e in self.elites.items():
            g[i - i0, j - j0] = e.logL
        return np.ma.masked_invalid(g)

    # -- accessors for downstream analysis and plotting -------------------
    # hifuku computes; the caller plots.  These return plain arrays and
    # dataframes in barycentric or Cartesian coordinates.

    def points(self, coords: str = "barycentric", anchors=None):
        """Scattered elite points as ``(x, y, logL, z)`` arrays.

        ``coords="barycentric"`` returns the niche centers ``(lam1, lam2)``;
        ``coords="cartesian"`` maps them through the anchor triangle into the
        Euclidean CBS plane.  ``anchors`` defaults to the archive's stored
        ``anchors``; a cartesian request with neither is an error.
        """
        from hifuku.utils import barycentric_to_cartesian
        if anchors is None:
            anchors = self.anchors
        keys = list(self.elites)
        lam1 = np.array([self.origin + (k[0] + 0.5) * self.cell for k in keys])
        lam2 = np.array([self.origin + (k[1] + 0.5) * self.cell for k in keys])
        logL = np.array([self.elites[k].logL for k in keys])
        z = np.array([self.elites[k].z for k in keys])
        if coords == "barycentric":
            return lam1, lam2, logL, z
        if coords == "cartesian":
            if anchors is None:
                raise ValueError("cartesian coords require anchors")
            x, y = barycentric_to_cartesian(lam1, lam2, anchors)
            return x, y, logL, z
        raise ValueError(f"coords must be 'barycentric' or 'cartesian', got {coords!r}")

    def records(self, coords: str = "barycentric", anchors=None) -> np.ndarray:
        """Scattered elevation records as an ``(N, 3)`` array.

        Each row is one elite ``(coord1, coord2, logL)``, in barycentric
        ``(lam1, lam2, logL)`` or Cartesian ``(x, y, logL)`` coordinates per
        ``coords``.  Unlike :meth:`surface`, this does no interpolation; it hands
        the raw scattered records to a plotting utility that triangulates them,
        for example ``ax.tricontourf(*archive.records(coords="cartesian",
        anchors=tri).T)``.
        """
        c1, c2, logL, _z = self.points(coords=coords, anchors=anchors)
        return np.column_stack([c1, c2, logL])

    def locate(self, tree, coords: str = "barycentric"):
        """Return the chart coordinates of a tree as ``(x, y, z)``.

        This method places ``tree`` in the same frame as the map.  It uses the
        archive's own anchors, taxon table, and metric.  A feature tree, such as
        the maximum-likelihood tree or a ufboot replicate, lands where it belongs
        on the map.  ``coords`` is "barycentric" or "cartesian".  ``z`` is the
        out-of-plane residual.
        """
        if self.anchors is None or self.taxon_table is None:
            raise ValueError(
                "archive lacks anchors or taxon_table; build it with "
                "run_archive or run_archive_gpu"
            )
        return locate_tree(tree, self.taxon_table, self.anchors, coords)

    def frame(self, anchors=None, backend: str = "pandas"):
        """Tidy dataframe of the elites (niche indices, coordinates, logL, z).

        Includes Cartesian ``x``, ``y`` columns when ``anchors`` is given or the
        archive has stored ``anchors``.
        """
        from hifuku.utils import elite_frame
        if anchors is None:
            anchors = self.anchors
        return elite_frame(self, anchors=anchors, backend=backend)

    def surface(self, n: int = 200, coords: str = "barycentric",
                anchors=None, radius=None, z_scale=None):
        """Interpolated elevation surface as ``(X, Y, Z)`` meshgrids.

        Shepard-interpolates the elite log-likelihoods over a regular ``n`` by
        ``n`` grid spanning the filled region, in barycentric or Cartesian
        coordinates.  ``Z`` is masked beyond the support radius.  The result is a
        plain gridded field: it drops into ``ax.contourf(X, Y, Z)``,
        ``ax.pcolormesh(X, Y, Z)``, ``ax.plot_surface(X, Y, Z)``, and the like.
        """
        from hifuku.utils import shepard_grid
        if self.n_filled == 0:
            raise ValueError("empty archive")
        px, py, logL, z = self.points(coords=coords, anchors=anchors)
        xs = np.linspace(px.min(), px.max(), n)
        ys = np.linspace(py.min(), py.max(), n)
        X, Y = np.meshgrid(xs, ys)
        Z = shepard_grid(np.column_stack([px, py]), logL, X, Y,
                         radius=radius, z=(z if z_scale else None), z_scale=z_scale)
        return X, Y, Z


def locate_tree(tree, taxon_table, triangle, coords="barycentric"):
    """Return the chart coordinates of a tree as ``(x, y, z)``.

    This function aligns the leaves of the tree to ``taxon_table``.  It measures
    the distance from the tree to each anchor of ``triangle`` with the chart's
    own metric, then solves for the chart position.

    ``coords="barycentric"`` returns ``(lambda1, lambda2, z)``.
    ``coords="cartesian"`` returns the point in the Euclidean metric plane.
    ``z`` is the out-of-plane residual.  It measures how far the tree sits off
    the anchor plane.

    ``triangle`` provides the anchor trees, their embedded geometry, and the
    metric.  The chart owns its metric so a tree cannot be placed under a metric
    inconsistent with the chart it lands on.
    """
    from hifuku.utils import barycentric_to_cartesian
    metric = triangle.tree_metric
    anchors = (triangle.r1, triangle.r2, triangle.r3)
    _set_global_leaf_indices(tree, taxon_table)
    for a in anchors:
        _set_global_leaf_indices(a, taxon_table)
    s = [float(metric(tree, a)[0]) for a in anchors]
    lam, z = barycentric(s[0], s[1], s[2], triangle)
    lam1, lam2 = float(lam[0]), float(lam[1])
    if coords == "barycentric":
        return lam1, lam2, float(z)
    if coords == "cartesian":
        x, y = barycentric_to_cartesian(lam1, lam2, triangle)
        return float(x), float(y), float(z)
    raise ValueError(f"coords must be 'barycentric' or 'cartesian', got {coords!r}")


def _vary(tree, taxon_table, rng, sigma_slide, scale_width):
    """Apply one tree move as the variation operator.  Returns a new tree or None.

    The move mix reuses the ``P_MOVE_*`` schedule.  The moves return a copy, so
    the parent elite is never modified.
    """
    u = float(rng.random())
    if u < P_MOVE_SPR:
        nt, _ = spr_move(tree, taxon_table, rng)
    elif u < P_MOVE_SPR + P_MOVE_NNI:
        nt, _ = nni_move(tree, taxon_table, rng)
    elif u < P_MOVE_SPR + P_MOVE_NNI + P_MOVE_SLIDE:
        nt, _ = branch_slide_move(tree, taxon_table, rng, sigma=sigma_slide)
    else:
        nt, _ = branch_scale_move(tree, taxon_table, rng, width=scale_width)
    return nt


def run_archive(
    r1: HifukuTree,
    r2: HifukuTree,
    r3: HifukuTree,
    alignment,
    model,
    start_trees,
    triangle: AnchorTriangle,
    taxon_table: TaxonTable,
    cell: float = ARCHIVE_CELL,
    origin: float = 0.0,
    n_iters: int = ARCHIVE_N_ITERS,
    seed: int = 0,
    sigma_slide: float = DEFAULT_SIGMA_SLIDE,
    scale_width: float = DEFAULT_SCALE_WIDTH,
    batch: int = ARCHIVE_BATCH,
    converge: bool = True,
    force_full_run: bool = False,
    gate_window: int = ARCHIVE_GATE_WINDOW,
    coverage_eps: float = ARCHIVE_COVERAGE_EPS,
    precision_eps: float = ARCHIVE_PRECISION_EPS,
    logl_margin: float | None = ARCHIVE_LOGL_MARGIN,
    logl_floor: float | None = None,
    monitor=False,
) -> ArchiveResult:
    """Run a CPU elite-archive survey for one alignment.

    The three anchor trees fix the chart.  The archive is seeded with the anchors
    and the start trees.  The survey then repeats a pass: select a random
    occupied niche, vary its elite, evaluate the offspring fitness and niche, and
    place it.  Fitness is the alignment log-likelihood.

    This function builds a :class:`~hifuku.cpu_backend.CpuBackend` and gives it
    to :func:`~hifuku.driver.run_survey`.  The loop and the halt rule are in the
    driver, which the GPU survey also uses.  One rule then has one
    implementation.

    The survey runs ``batch`` variations between two checkpoints, up to
    ``n_iters``.  When ``converge`` is set, it halts on discovery saturation: the
    trailing-window coverage rate and precision rate both fall to or below their
    thresholds.  Coverage is the crisp signal.  Precision uses a loose threshold
    because refinement inside a niche never fully stops.  ``force_full_run``
    turns the halt off.

    Parameters
    ----------
    r1, r2, r3 : HifukuTree
        Anchor trees that fix the chart.  Used only for CV distances.
    alignment, model
        The alignment surveyed and its substitution model.
    start_trees : list[HifukuTree]
        Extra seed trees, normally the anchor tree for the surveyed gene.
    triangle : AnchorTriangle
        Anchor geometry.  It carries the chart metric.
    taxon_table : TaxonTable
        Shared namespace.
    cell : float
        Niche side in barycentric units.  The grid is unbounded.
    origin : float
        Grid origin on both axes.
    n_iters : int
        The survey budget cap in variations.
    seed : int
        RNG seed.
    sigma_slide, scale_width : float
        Proposal widths for the branch moves.
    batch : int
        Variations between two checkpoints.
    converge : bool
        Halt on discovery saturation when set.
    force_full_run : bool
        Run the full budget and ignore the halt.
    gate_window : int
        Trailing window in checkpoints for the halt rates.
    coverage_eps, precision_eps : float
        Halt thresholds on the windowed coverage and precision rates.
    logl_margin : float, optional
        Relative log-likelihood gate: a variation makes a niche only when its
        tree is within this many nats of the best tree found.  The floor follows
        the best, and the driver reads it once per checkpoint.  Pass None for a
        survey that only the budget limits.
    logl_floor : float, optional
        Absolute log-likelihood gate.  Useful for a common domain across genes.
        Not permitted together with ``logl_margin``.
    monitor : callable, None or False
        A checkpoint callback.  False, the default, reports nothing.  None
        selects the default reporter.  See :mod:`hifuku.monitor`.

    Returns
    -------
    ArchiveResult
        The archive, its per-checkpoint history, and the halt state.
    """
    from hifuku.cpu_backend import CpuBackend
    from hifuku.driver import run_survey
    from hifuku.params import ArchiveParams

    backend = CpuBackend()
    params = ArchiveParams.resolve(backend.caps.defaults, {
        "cell": cell,
        "origin": origin,
        "n_iters": n_iters,
        "seed": seed,
        "sigma_slide": sigma_slide,
        "scale_width": scale_width,
        "checkpoint_every": batch,
        "converge": converge,
        "force_full_run": force_full_run,
        "gate_window": gate_window,
        "coverage_eps": coverage_eps,
        "precision_eps": precision_eps,
        "logl_margin": logl_margin,
        "logl_floor": logl_floor,
    })
    ctx = RunContext(anchors=(r1, r2, r3), alignment=alignment, model=model,
                     start_trees=list(start_trees), triangle=triangle,
                     taxon_table=taxon_table)
    return run_survey(backend, ctx, params, monitor=monitor)
