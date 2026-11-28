import java.util.Arrays;

public class Solution {
    public boolean find3Numbers(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (curSum == target) return true;
                else if (curSum < target) l++;
                else r--;
            }
        }
        return false;
    }
}