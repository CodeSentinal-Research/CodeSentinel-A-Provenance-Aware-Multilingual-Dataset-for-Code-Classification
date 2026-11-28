public class Solution {
    public int maxDistToClosest(int[] seats) {
        int n = seats.length;
        int prev = -1, maxDist = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prev == -1) maxDist = i;
                else maxDist = Math.max(maxDist, (i - prev) / 2);
                prev = i;
            }
        }
        return Math.max(maxDist, n - 1 - prev);
    }
}