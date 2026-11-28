public class Solution {
    public int[] mergeSorted(int[] a, int[] b) {
        int m = a.length, n = b.length;
        int[] res = new int[m + n];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
            res[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
        while (i < m) res[k++] = a[i++];
        while (j < n) res[k++] = b[j++];
        return res;
    }
}
