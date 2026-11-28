public class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int l = 0, r = n - 1, pos = n - 1;

        // Binary search loop to narrow down range
        while (l <= r) {
            if (Math.abs(nums[l]) > Math.abs(nums[r])) {
                res[pos] = nums[l] * nums[l];
                l++;
            } else {
                res[pos] = nums[r] * nums[r];
                r--;
            }
            pos--;
        }
        return res;
    }
}