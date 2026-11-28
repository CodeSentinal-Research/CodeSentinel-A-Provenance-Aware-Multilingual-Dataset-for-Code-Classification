public class Solution {
    public int maxSumIS(int[] arr, int n) {
        int[] msis = new int[n];
        for (int i = 0; i < n; i++) msis[i] = arr[i];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                    msis[i] = msis[j] + arr[i];
                }
            }
        }

        int max = 0;
        for (int x : msis) if (x > max) max = x;
        return max;
    }
}