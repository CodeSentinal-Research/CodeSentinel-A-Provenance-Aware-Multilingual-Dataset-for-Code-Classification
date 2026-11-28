import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.length;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (Math.abs(curSum - target) < Math.abs(closest - target)) {
                    closest = curSum;
                }
                if (curSum < target) l++;
                else if (curSum > target) r--;
                else return target;
            }
        }
        return closest;
    }
}