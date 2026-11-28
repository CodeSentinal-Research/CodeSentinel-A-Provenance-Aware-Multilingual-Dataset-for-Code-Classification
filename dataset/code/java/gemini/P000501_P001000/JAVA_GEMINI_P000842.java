public class Solution {
    private long calcSum(long count, long val) {
        if (val >= count) {
            return (val + val - count + 1) * count / 2;
        } else {
            return (val + 1) * val / 2 + (count - val);
        }
    }

    public int maxValue(int n, int index, int maxSum) {
        long leftCount = index;
        long rightCount = n - 1 - index;
        long low = 1, high = maxSum;
        long ans = 1;
        // Binary search loop to narrow down range
        while (low <= high) {
            // Calculate midpoint to prevent potential overflow
            long mid = low + (high - low) / 2;
            long total = mid + calcSum(leftCount, mid - 1) + calcSum(rightCount, mid - 1);
            if (total <= maxSum) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int) ans;
    }
}