import java.util.*;
public class Solution {
    private void merge(int[] arr, int l, int m, int r) {
        int[] L = Arrays.copyOfRange(arr, l, m+1);
        int[] R = Arrays.copyOfRange(arr, m+1, r+1);
        int i=0, j=0, k=l;
        while (i<L.length && j<R.length) arr[k++] = L[i]<=R[j] ? L[i++] : R[j++];
        while (i<L.length) arr[k++] = L[i++];
        while (j<R.length) arr[k++] = R[j++];
    }
    public void mergeSort(int[] arr, int l, int r) {
        if (l < r) { int m = l+(r-l)/2; mergeSort(arr,l,m); mergeSort(arr,m+1,r); merge(arr,l,m,r); }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        new Solution().mergeSort(arr, 0, n-1);
        System.out.println(Arrays.toString(arr).replaceAll("[\[\],]","").trim());
    }
}
