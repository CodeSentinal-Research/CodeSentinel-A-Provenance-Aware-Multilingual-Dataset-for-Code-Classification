public class Solution {
    public int deleteAndEarn(int[] nums) {
        int maxVal = 0;
        for (int x : nums) maxVal = Math.max(maxVal, x);

        int[] count = new int[maxVal + 1];
        for (int x : nums) count[x] += x;

        int rob1 = 0, rob2 = 0;
        for (int v : count) {
            int tmp = Math.max(rob1 + v, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
}