public class Solution {
    public long maximumSumSubarray(int k, int[] arr, int n) {
        long curSum = 0;
        for (int i = 0; i < k; i++) curSum += arr[i];
        long maxSum = curSum;

        for (int i = k; i < n; i++) {
            curSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, curSum);
        }
        return maxSum;
    }
}