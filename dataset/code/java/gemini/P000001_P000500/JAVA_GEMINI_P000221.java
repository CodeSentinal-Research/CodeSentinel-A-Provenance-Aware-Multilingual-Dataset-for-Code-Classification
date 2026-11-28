import java.util.Arrays;

public class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
        int curEnd = Integer.MIN_VALUE;
        int chain = 0;

        for (int[] p : pairs) {
            if (p[0] > curEnd) {
                chain++;
                curEnd = p[1];
            }
        }
        return chain;
    }
}