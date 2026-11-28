public class Solution {
    public long largestSumK(int[] nums, int k) {
        long win = 0;
        for (int i=0;i<k;i++) win+=nums[i];
        long best = win;
        for (int i=k;i<nums.length;i++) {
            win += nums[i]-nums[i-k];
            if (win>best) best=win;
        }
        return best;
    }
}
