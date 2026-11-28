public class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long ans = 1, curLen = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                curLen++;
            } else {
                curLen = 1;
            }
            ans += curLen;
        }
        return ans;
    }
}