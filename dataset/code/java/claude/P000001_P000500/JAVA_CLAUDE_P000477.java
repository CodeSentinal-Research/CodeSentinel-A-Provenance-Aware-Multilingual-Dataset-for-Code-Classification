import java.util.*;
public class Solution {
    private void reverse(int[] arr, int lo, int hi) {
        while (lo < hi) { int t=arr[lo];arr[lo]=arr[hi];arr[hi]=t; lo++; hi--; }
    }
    public void rotate(int[] arr, int k) {
        int n = arr.length; k %= n;
        reverse(arr,0,n-1); reverse(arr,0,k-1); reverse(arr,k,n-1);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(), k=sc.nextInt(); int[] arr = new int[n];
        for (int i=0;i<n;i++) arr[i]=sc.nextInt();
        new Solution().rotate(arr,k);
        System.out.println(Arrays.toString(arr).replaceAll("[\[\],]","").trim());
    }
}
