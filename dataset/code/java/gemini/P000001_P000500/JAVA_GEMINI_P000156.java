public class Solution {
    public int maxConsecutiveZeros(int[] nums) {
        int maxZeros = 0, curZeros = 0;
        for (int x : nums) {
            if (x == 0) {
                curZeros++;
                maxZeros = Math.max(maxZeros, curZeros);
            } else {
                curZeros = 0;
            }
        }
        return maxZeros;
    }
}