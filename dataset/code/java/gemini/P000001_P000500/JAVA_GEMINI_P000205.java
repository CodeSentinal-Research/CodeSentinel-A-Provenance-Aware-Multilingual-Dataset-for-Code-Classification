import java.util.Arrays;

public class Solution {
    public double getMedian(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int[] merged = new int[2 * n];
        System.arraycopy(arr1, 0, merged, 0, n);
        System.arraycopy(arr2, 0, merged, n, n);
        Arrays.sort(merged);
        return (merged[n - 1] + merged[n]) / 2.0;
    }
}