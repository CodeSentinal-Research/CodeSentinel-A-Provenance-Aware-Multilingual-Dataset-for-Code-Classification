public class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int left = 1, right = 0;
        for (int q : quantities) right = Math.max(right, q);
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int needed = 0;
            for (int q : quantities) {
                needed += (q + mid - 1) / mid;
            }
            if (needed <= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}