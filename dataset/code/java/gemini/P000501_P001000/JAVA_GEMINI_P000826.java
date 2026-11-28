public class Solution {
    public int arrangeCoins(int n) {
        long left = 1, right = n;
        long ans = 0;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long mid = left + (right - left) / 2;
            long curr = (mid * (mid + 1)) / 2;
            if (curr <= n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int) ans;
    }
}