public class Solution {
    public int findSmallest(int[] nums) {
        int min = nums[0];
        for (int x : nums) if (x < min) min = x;
        return min;
    }
}
