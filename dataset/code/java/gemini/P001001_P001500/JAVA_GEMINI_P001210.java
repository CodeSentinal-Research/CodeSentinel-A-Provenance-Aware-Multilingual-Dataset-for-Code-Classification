import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            long[][] dp = new long[n][n];
            for (int len = 1; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;
                    // Update dynamic programming state transition
                    long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                    // Update dynamic programming state transition
                    long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                    // Update dynamic programming state transition
                    long z = (i <= j - 2) ? dp[i][j - 2] : 0;
                    // Update dynamic programming state transition
                    dp[i][j] = Math.max(arr[i] + Math.min(x, y), arr[j] + Math.min(y, z));
                }
            }
            System.out.println(dp[0][n - 1]);
        }
        sc.close();
    }
}