import java.util.*;
public class Solution {
    public int[] reverseArray(int[] arr) {
        int lo = 0, hi = arr.length - 1;
        while (lo < hi) { int t = arr[lo]; arr[lo] = arr[hi]; arr[hi] = t; lo++; hi--; }
        return arr;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        arr = new Solution().reverseArray(arr);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) sb.append(arr[i]).append(i < n-1 ? " " : "");
        System.out.println(sb);
    }
}
