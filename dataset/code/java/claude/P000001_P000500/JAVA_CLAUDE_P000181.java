public class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length;
        int[] pre = new int[n + 1];
        for (int i = 0; i < n; i++) pre[i+1] = pre[i] + nums[i];
        return Math.max(solve(pre, n, firstLen, secondLen), solve(pre, n, secondLen, firstLen));
    }
    private int solve(int[] pre, int n, int L, int M) {
        int best = 0, res = 0;
        for (int i = L + M - 1; i < n; i++) {
            best = Math.max(best, pre[i - M + 1] - pre[i - M + 1 - L]);
            res = Math.max(res, best + pre[i + 1] - pre[i + 1 - M]);
        }
        return res;
    }
}
