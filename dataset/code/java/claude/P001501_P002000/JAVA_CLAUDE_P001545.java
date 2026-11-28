import java.util.*;
public class Solution {
    public int[] findMaxMin(int[] arr) {
        int mx = arr[0], mn = arr[0];
        for (int x : arr) { mx = Math.max(mx,x); mn = Math.min(mn,x); }
        return new int[]{mx, mn};
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        int[] r = new Solution().findMaxMin(arr);
        System.out.println("Max: " + r[0] + "\nMin: " + r[1]);
    }
}
