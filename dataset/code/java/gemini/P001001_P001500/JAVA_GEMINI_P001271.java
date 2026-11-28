public class Solution {
    public int minTaps(int n, int[] ranges) {
        int[] maxReach = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            int left = Math.max(0, i - ranges[i]);
            int right = Math.min(n, i + ranges[i]);
            maxReach[left] = Math.max(maxReach[left], right);
        }

        int taps = 0, curEnd = 0, nextEnd = 0;
        for (int i = 0; i < n; i++) {
            nextEnd = Math.max(nextEnd, maxReach[i]);
            if (i == curEnd) {
                if (nextEnd <= i) return -1;
                taps++;
                curEnd = nextEnd;
            }
        }
        return taps;
    }
}