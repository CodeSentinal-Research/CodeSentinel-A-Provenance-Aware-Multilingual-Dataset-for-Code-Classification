public class Solution {
    public int[] printNosReverse(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = n - i;
        }
        return res;
    }
}
