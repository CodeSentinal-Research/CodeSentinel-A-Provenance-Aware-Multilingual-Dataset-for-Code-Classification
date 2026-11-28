import java.util.*;

public class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> (a[0] == b[0]) ? b[1] - a[1] : a[0] - b[0]);
        int[] tails = new int[envelopes.length];
        int size = 0;

        for (int[] env : envelopes) {
            int h = env[1];
            int i = 0, j = size;
            while (i < j) {
                int m = (i + j) / 2;
                if (tails[m] < h) i = m + 1;
                else j = m;
            }
            tails[i] = h;
            if (i == size) size++;
        }
        return size;
    }
}