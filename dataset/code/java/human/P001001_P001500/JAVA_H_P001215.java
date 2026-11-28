package dp.l6;

import java.util.Arrays;

/**
 * LeetCode 546 / Remove Boxes — repeatedly remove a contiguous run of {@code k} equal boxes to score
 * {@code k * k}; return the maximum total score. Presented twice: a top-down memoised recursion and the
 * equivalent bottom-up tabulation, so students can compare the two idioms for the same interval DP.
 *
 * <p><b>Interval DP with a third "attached run" dimension.</b> A plain {@code dp[left][right]} is not
 * enough, because the best score for a range depends on how many boxes equal to {@code boxes[right]} are
 * already stuck to its right (they were left over from an earlier split). So the state gains a third
 * index {@code attached}: {@code dp[left][right][attached]} = the best score for {@code boxes[left..right]}
 * given that {@code attached} extra boxes of the same colour as {@code boxes[right]} sit immediately to
 * the right of {@code right}.
 *
 * <p><b>The two choices (the "last action" split).</b>
 * <ol>
 *   <li>Remove {@code boxes[right]} together with its {@code attached} companions now, scoring
 *       {@code (attached + 1)^2}, and solve {@code [left..right-1]} with nothing attached.
 *   <li>For any {@code i &lt; right} with {@code boxes[i] == boxes[right]}, merge {@code boxes[i]} with the
 *       right group first (so it can be removed together later): clear the middle {@code [i+1..right-1]},
 *       then solve {@code [left..i]} with {@code attached + 1} boxes attached.
 * </ol>
 * Consecutive equal boxes at the right end are folded into {@code attached} up front, which both prunes
 * work and canonicalises the memo key.
 *
 * <p><b>Complexity:</b> O(n^4) states-times-transition in the worst case, O(n^3) space.
 *
 * <p><b>Idiomatic-Java rationale:</b> the top-down memo uses an {@code int[][][]} pre-filled with
 * {@code -1} as the "not computed" marker (valid scores are non-negative) instead of a boxed
 * {@code Integer[][][]} with {@code null}, avoiding autoboxing; the bottom-up variant leans on the fact
 * that a zero-initialised {@code int[][][]} already encodes the empty-range base case (score 0).
 */
public class RemoveBoxes {

    /** Top-down: 3D memoised recursion on {@code (left, right, attached)}. */
    public int removeBoxesTopDown(int[] boxes) {
        int n = boxes.length;
        int[][][] memo = new int[n][n][n];
        for (int[][] plane : memo) {
            for (int[] row : plane) {
                Arrays.fill(row, -1); // -1 = state not yet computed; real scores are >= 0
            }
        }
        return bestScore(boxes, memo, 0, n - 1, 0);
    }

    private int bestScore(int[] boxes, int[][][] memo, int left, int right, int attached) {
        if (left > right) {
            return 0;
        }

        // Fold trailing equal boxes into `attached` so they are removed as one group and the memo key
        // is canonical.
        while (right > left && boxes[right] == boxes[right - 1]) {
            right--;
            attached++;
        }
        if (memo[left][right][attached] != -1) {
            return memo[left][right][attached];
        }

        // Choice 1: remove boxes[right] plus its attached companions immediately.
        int best = bestScore(boxes, memo, left, right - 1, 0) + (attached + 1) * (attached + 1);

        // Choice 2: postpone by merging an equal box further left with the right group.
        for (int i = left; i < right; i++) {
            if (boxes[i] == boxes[right]) {
                best = Math.max(
                        best,
                        bestScore(boxes, memo, left, i, attached + 1)
                                + bestScore(boxes, memo, i + 1, right - 1, 0));
            }
        }

        memo[left][right][attached] = best;
        return best;
    }

    /** Bottom-up: the same recurrence tabulated by increasing range length. */
    public int removeBoxesBottomUp(int[] boxes) {
        int n = boxes.length;
        int[][][] dp = new int[n][n][n];

        // Base case: a single box with `attached` companions of its colour scores (attached + 1)^2.
        for (int index = 0; index < n; index++) {
            for (int attached = 0; attached <= index; attached++) {
                dp[index][index][attached] = (attached + 1) * (attached + 1);
            }
        }

        for (int length = 1; length < n; length++) {
            for (int right = length; right < n; right++) {
                int left = right - length;
                for (int attached = 0; attached <= left; attached++) {
                    // Choice 1: remove boxes[left] with its attached companions, then solve the rest.
                    int best = (attached + 1) * (attached + 1) + dp[left + 1][right][0];

                    // Choice 2: merge an equal box in (left, right] with the left group first. The empty
                    // middle dp[left+1][mid-1][0] when mid == left+1 is the zero-initialised base case.
                    for (int mid = left + 1; mid <= right; mid++) {
                        if (boxes[mid] == boxes[left]) {
                            best = Math.max(
                                    best, dp[left + 1][mid - 1][0] + dp[mid][right][attached + 1]);
                        }
                    }

                    dp[left][right][attached] = best;
                }
            }
        }

        return dp[0][n - 1][0];
    }
}
