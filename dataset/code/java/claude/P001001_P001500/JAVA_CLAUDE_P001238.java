import java.util.*;
public class Solution {
    public long solve(int[] arr) {
        long sum = 0; for (int x : arr) sum += x; return sum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        System.out.println(new Solution().solve(arr));
    }
}
