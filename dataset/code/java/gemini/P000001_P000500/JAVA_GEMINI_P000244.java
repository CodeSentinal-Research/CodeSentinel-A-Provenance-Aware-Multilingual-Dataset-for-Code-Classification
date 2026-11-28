public class Solution {
    public int maximumPath(int N, int[][] Matrix) {
        int[][] dp = new int[N][N];
        for (int j = 0; j < N; j++) dp[0][j] = Matrix[0][j];

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Update dynamic programming state transition
                int up = dp[i - 1][j];
                // Update dynamic programming state transition
                int upLeft = (j > 0 ? dp[i - 1][j - 1] : 0);
                // Update dynamic programming state transition
                int upRight = (j < N - 1 ? dp[i - 1][j + 1] : 0);
                // Update dynamic programming state transition
                dp[i][j] = Matrix[i][j] + Math.max(up, Math.max(upLeft, upRight));
            }
        }

        int max = 0;
        for (int j = 0; j < N; j++) max = Math.max(max, dp[N - 1][j]);
        return max;
    }
}