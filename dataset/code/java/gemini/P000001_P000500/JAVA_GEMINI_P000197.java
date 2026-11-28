public class Solution {
    public long minimumSumSubarray(int k, int[] arr, int n) {
        long curSum = 0;
        for (int i = 0; i < k; i++) curSum += arr[i];
        long minSum = curSum;

        for (int i = k; i < n; i++) {
            curSum += arr[i] - arr[i - k];
            minSum = Math.min(minSum, curSum);
        }
        return minSum;
    }
}