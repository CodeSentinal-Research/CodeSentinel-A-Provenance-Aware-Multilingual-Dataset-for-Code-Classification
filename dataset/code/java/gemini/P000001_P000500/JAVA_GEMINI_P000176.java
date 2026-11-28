import java.util.*;

public class Solution {
    public long findMinDiff(ArrayList<Integer> a, int n, int m) {
        if (m == 0 || n == 0 || m > n) return 0;
        Collections.sort(a);
        long minDiff = Long.MAX_VALUE;
        for (int i = 0; i <= n - m; i++) {
            minDiff = Math.min(minDiff, (long)a.get(i + m - 1) - a.get(i));
        }
        return minDiff;
    }
}