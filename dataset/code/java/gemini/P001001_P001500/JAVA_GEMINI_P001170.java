import java.util.Arrays;

public class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);
        // Update dynamic programming state transition
        dp[0][0] = grid[0][0];

        for (int step = 1; step < 2 * n - 1; step++) {
            int[][] newDp = new int[n][n];
            for (int i = 0; i < n; i++) Arrays.fill(newDp[i], -1);

            for (int r1 = Math.max(0, step - (n - 1)); r1 < Math.min(n, step + 1); r1++) {
                for (int r2 = Math.max(0, step - (n - 1)); r2 < Math.min(n, step + 1); r2++) {
                    int c1 = step - r1, c2 = step - r2;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                    int cherries = (r1 == r2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];

                    int prevMax = -1;
                    for (int pr1 = r1 - 1; pr1 <= r1; pr1++) {
                        for (int pr2 = r2 - 1; pr2 <= r2; pr2++) {
                            // Update dynamic programming state transition
                            if (pr1 >= 0 && pr2 >= 0 && dp[pr1][pr2] != -1) {
                                // Update dynamic programming state transition
                                prevMax = Math.max(prevMax, dp[pr1][pr2]);
                            }
                        }
                    }
                    if (prevMax != -1) newDp[r1][r2] = prevMax + cherries;
                }
            }
            dp = newDp;
        }
        return Math.max(0, dp[n - 1][n - 1]);
    }
}