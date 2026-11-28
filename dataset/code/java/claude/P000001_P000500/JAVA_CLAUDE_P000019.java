public class Solution {
    public int[] getMultiplicationTable(int n, int limit) {
        int[] res = new int[limit];
        for (int i = 1; i <= limit; i++) {
            res[i - 1] = n * i;
        }
        return res;
    }
}
