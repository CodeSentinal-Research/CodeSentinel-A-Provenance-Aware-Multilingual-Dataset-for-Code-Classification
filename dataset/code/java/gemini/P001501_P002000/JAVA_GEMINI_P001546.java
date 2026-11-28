public class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int maxLen = 0, l = 0, n = nums.length;

        while (l < n) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l;
                while (r + 1 < n && nums[r + 1] <= threshold && nums[r] % 2 != nums[r + 1] % 2) {
                    r++;
                }
                maxLen = Math.max(maxLen, r - l + 1);
                l = r + 1;
            } else {
                l++;
            }
        }
        return maxLen;
    }
}