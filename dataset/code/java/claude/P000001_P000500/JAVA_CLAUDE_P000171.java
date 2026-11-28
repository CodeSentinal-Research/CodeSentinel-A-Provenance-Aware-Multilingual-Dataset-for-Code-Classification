public class Solution {
    public int[] segregate01(int[] nums) {
        int zeros = 0;
        for (int x : nums) if (x == 0) zeros++;
        int[] res = new int[nums.length];
        for (int i = zeros; i < nums.length; i++) res[i] = 1;
        return res;
    }
}
