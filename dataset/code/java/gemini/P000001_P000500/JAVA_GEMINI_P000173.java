public class Solution {
    public int maxDiff(int[] arr) {
        if (arr.length < 2) return 0;
        int minVal = arr[0];
        int maxDiff = arr[1] - arr[0];

        for (int i = 1; i < arr.length; i++) {
            maxDiff = Math.max(maxDiff, arr[i] - minVal);
            minVal = Math.min(minVal, arr[i]);
        }
        return maxDiff;
    }
}