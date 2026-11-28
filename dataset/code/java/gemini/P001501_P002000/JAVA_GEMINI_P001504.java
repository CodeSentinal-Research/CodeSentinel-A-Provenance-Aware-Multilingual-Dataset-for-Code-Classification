public class Solution {
    public int longestNiceSubarray(int[] nums) {
        int usedBits = 0, l = 0, maxLen = 0;

        for (int r = 0; r < nums.length; r++) {
            while ((usedBits & nums[r]) != 0) {
                usedBits ^= nums[l++];
            }
            usedBits |= nums[r];
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}