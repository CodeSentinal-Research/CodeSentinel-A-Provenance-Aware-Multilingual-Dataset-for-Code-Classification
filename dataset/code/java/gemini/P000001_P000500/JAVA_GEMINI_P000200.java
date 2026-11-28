public class Solution {
    public int[] twoOddNum(int[] arr, int n) {
        int xorAll = 0;
        for (int v : arr) xorAll ^= v;

        int diffBit = xorAll & (-xorAll);
        int x = 0, y = 0;
        for (int v : arr) {
            if ((v & diffBit) != 0) x ^= v;
            else y ^= v;
        }

        return new int[]{Math.max(x, y), Math.min(x, y)};
    }
}