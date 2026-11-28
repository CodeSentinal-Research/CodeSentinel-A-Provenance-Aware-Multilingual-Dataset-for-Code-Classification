public class Solution {
    public int equilibriumPoint(long[] arr, int n) {
        long totalSum = 0;
        for (long x : arr) totalSum += x;
        long leftSum = 0;

        for (int i = 0; i < n; i++) {
            if (leftSum == totalSum - leftSum - arr[i]) return i + 1;
            leftSum += arr[i];
        }
        return -1;
    }
}