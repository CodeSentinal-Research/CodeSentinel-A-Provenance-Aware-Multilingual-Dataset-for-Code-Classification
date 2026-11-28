public class Solution {
    public int findEquilibriumIndex(int[] nums) {
        long totalSum = 0;
        for (int x : nums) totalSum += x;
        long leftSum = 0;

        for (int i = 0; i < nums.length; i++) {
            if (leftSum == totalSum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
}