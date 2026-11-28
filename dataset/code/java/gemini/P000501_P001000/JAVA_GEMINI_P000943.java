import java.util.Arrays;

public class Solution {
    private int[][] memo;
    private int[] suffix;
    private int n;

    private int dp(int i, int m) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffix[i];
        if (memo[i][m] != -1) return memo[i][m];

        int res = 0;
        for (int x = 1; x <= 2 * m; x++) {
            res = Math.max(res, suffix[i] - dp(i + x, Math.max(m, x)));
        }
        return memo[i][m] = res;
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;
        suffix = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        memo = new int[n][n + 1];
        for (int[] row : memo) Arrays.fill(row, -1);
        return dp(0, 1);
    }
}