import java.util.Arrays;

public class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int maxPair = 0;
        for (int i = 0; i < n / 2; i++) {
            maxPair = Math.max(maxPair, nums[i] + nums[n - 1 - i]);
        }
        return maxPair;
    }
}