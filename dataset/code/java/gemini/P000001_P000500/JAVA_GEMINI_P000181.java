public class Solution {
    private int helper(int[] nums, int L, int M) {
        int sumL = 0, sumM = 0;
        for (int i = 0; i < L; i++) sumL += nums[i];
        for (int i = L; i < L + M; i++) sumM += nums[i];

        int maxL = sumL;
        int ans = sumL + sumM;

        for (int i = L + M; i < nums.length; i++) {
            sumL += nums[i - M] - nums[i - L - M];
            maxL = Math.max(maxL, sumL);
            sumM += nums[i] - nums[i - M];
            ans = Math.max(ans, maxL + sumM);
        }
        return ans;
    }

    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        return Math.max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
}