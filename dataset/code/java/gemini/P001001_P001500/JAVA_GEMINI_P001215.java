public class Solution {
    private int[][][] memo;

    private int dp(int[] boxes, int l, int r, int k) {
        if (l > r) return 0;
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        if (memo[l][r][k] > 0) return memo[l][r][k];

        int res = dp(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                res = Math.max(res, dp(boxes, i + 1, r - 1, 0) + dp(boxes, l, i, k + 1));
            }
        }
        return memo[l][r][k] = res;
    }

    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        memo = new int[n][n][n];
        return dp(boxes, 0, n - 1, 0);
    }
}