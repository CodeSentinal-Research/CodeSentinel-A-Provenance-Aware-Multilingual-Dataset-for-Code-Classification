public class Solution {
    public int[] singleNumber(int[] nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;
        int diff = xorAll & (-xorAll);
        int a = 0, b = 0;
        for (int x : nums) {
            if ((x & diff) != 0) a ^= x;
            else b ^= x;
        }
        return new int[]{a, b};
    }
}