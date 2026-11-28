public class Solution {
    private long merge(long[] arr, long[] temp, int l, int mid, int r) {
        int i = l, j = mid + 1, k = l;
        long inv = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv += (mid - i + 1);
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];

        for (i = l; i <= r; i++) arr[i] = temp[i];
        return inv;
    }

    private long mergeSort(long[] arr, long[] temp, int l, int r) {
        long inv = 0;
        if (l < r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            inv += mergeSort(arr, temp, l, mid);
            inv += mergeSort(arr, temp, mid + 1, r);
            inv += merge(arr, temp, l, mid, r);
        }
        return inv;
    }

    public long inversionCount(long[] arr, long N) {
        long[] temp = new long[(int)N];
        return mergeSort(arr, temp, 0, (int)N - 1);
    }
}