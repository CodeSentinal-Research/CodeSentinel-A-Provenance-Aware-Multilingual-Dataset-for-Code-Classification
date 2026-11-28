public class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long minT = Long.MAX_VALUE;
        for (int t : time) minT = Math.min(minT, t);

        long l = 1, r = minT * totalTrips, ans = r;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long mid = l + (r - l) / 2;
            long trips = 0;
            for (int t : time) trips += mid / t;

            if (trips >= totalTrips) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}