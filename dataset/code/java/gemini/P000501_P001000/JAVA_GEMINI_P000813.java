public class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;
        long left = 1, right = x / 2;
        long ans = 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long mid = left + (right - left) / 2;
            if (mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int) ans;
    }
}