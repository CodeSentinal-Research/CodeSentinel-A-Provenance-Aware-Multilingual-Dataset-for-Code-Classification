public class Solution {
    public int getOddOccurrence(int[] arr) {
        int res = 0;
        for (int x : arr) res ^= x;
        return res;
    }
}