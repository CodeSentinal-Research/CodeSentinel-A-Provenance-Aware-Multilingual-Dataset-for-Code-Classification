public class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long total = 0;
        for (int b : batteries) total += b;
        long left = 1, right = total / n;
        long ans = 0;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long mid = left + (right - left) / 2;
            long curr = 0;
            for (int b : batteries) {
                curr += Math.min(b, mid);
            }
            if (curr >= mid * n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
}