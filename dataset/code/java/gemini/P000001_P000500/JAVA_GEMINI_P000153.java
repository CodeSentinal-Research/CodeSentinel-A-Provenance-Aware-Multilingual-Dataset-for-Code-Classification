public class Solution {
    public int[] rearrange(int[] nums) {
        int[] res = new int[nums.length];
        int idx = 0;
        for (int x : nums) {
            if (x >= 0) res[idx++] = x;
        }
        for (int x : nums) {
            if (x < 0) res[idx++] = x;
        }
        return res;
    }
}