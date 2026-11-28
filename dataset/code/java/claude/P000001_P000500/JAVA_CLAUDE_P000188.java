public class Solution {
    public int[] subarrayWithGivenSum(int[] nums, long target) {
        int l = 0; long cur = 0;
        for (int r = 0; r < nums.length; r++) {
            cur += nums[r];
            while (cur > target && l <= r) { cur -= nums[l++]; }
            if (cur == target) return new int[]{l, r};
        }
        return new int[]{};
    }
}
