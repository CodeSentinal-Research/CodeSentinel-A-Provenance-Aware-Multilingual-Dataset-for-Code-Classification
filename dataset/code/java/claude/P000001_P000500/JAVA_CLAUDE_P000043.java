public class Solution {
    public int[] printNos(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = i + 1;
        }
        return res;
    }
}
