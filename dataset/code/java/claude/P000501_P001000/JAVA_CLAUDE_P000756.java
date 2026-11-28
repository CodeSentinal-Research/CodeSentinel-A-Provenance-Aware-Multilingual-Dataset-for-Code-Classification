import java.util.*;
public class Solution {
    private int partition(int[] arr, int lo, int hi) {
        int pivot = arr[hi], i = lo-1;
        for (int j = lo; j < hi; j++) if (arr[j] <= pivot) { i++; int t=arr[i];arr[i]=arr[j];arr[j]=t; }
        int t=arr[i+1];arr[i+1]=arr[hi];arr[hi]=t; return i+1;
    }
    public void quickSort(int[] arr, int lo, int hi) {
        if (lo < hi) { int pi=partition(arr,lo,hi); quickSort(arr,lo,pi-1); quickSort(arr,pi+1,hi); }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        new Solution().quickSort(arr, 0, n-1);
        System.out.println(Arrays.toString(arr).replaceAll("[\[\],]","").trim());
    }
}
