import java.util.Arrays;

public class Solution {
    public int countTriplets(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (curSum == target) {
                    count++;
                    l++;
                    r--;
                } else if (curSum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return count;
    }
}