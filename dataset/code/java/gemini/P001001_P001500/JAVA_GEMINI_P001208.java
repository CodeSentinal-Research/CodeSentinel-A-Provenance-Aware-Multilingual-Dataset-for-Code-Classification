public class Solution {
    private int[][] memo;
    private int[] suffix;

    private int dp(int i, int m, int n) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffix[i];
        if (memo[i][m] > 0) return memo[i][m];

        int res = 0;
        for (int x = 1; x <= 2 * m; x++) {
            res = Math.max(res, suffix[i] - dp(i + x, Math.max(m, x), n));
        }
        return memo[i][m] = res;
    }

    public int stoneGameII(int[] piles) {
        int n = piles.length;
        suffix = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
        memo = new int[n + 1][n + 1];
        return dp(0, 1, n);
    }
}