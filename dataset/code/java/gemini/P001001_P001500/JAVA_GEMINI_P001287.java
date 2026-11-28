public class Solution {
    private boolean canDivide(int[] sweetness, int k, int target) {
        int pieces = 0, curSum = 0;
        for (int s : sweetness) {
            curSum += s;
            if (curSum >= target) {
                pieces++;
                curSum = 0;
            }
        }
        return pieces >= k + 1;
    }

    public int maximizeSweetness(int[] sweetness, int k) {
        int minVal = Integer.MAX_VALUE, total = 0;
        for (int s : sweetness) {
            minVal = Math.min(minVal, s);
            total += s;
        }

        int l = minVal, r = total / (k + 1), ans = l;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (canDivide(sweetness, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
}