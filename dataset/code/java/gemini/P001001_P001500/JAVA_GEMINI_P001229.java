public class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        double[][] dp = new double[n][n];
        // Update dynamic programming state transition
        dp[row][column] = 1.0;

        int[][] dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        for (int step = 0; step < k; step++) {
            double[][] newDp = new double[n][n];
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] > 0) {
                        for (int[] dir : dirs) {
                            int nr = r + dir[0], nc = c + dir[1];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                // Update dynamic programming state transition
                                newDp[nr][nc] += dp[r][c] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = newDp;
        }

        double sum = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) sum += dp[r][c];
        }
        return sum;
    }
}