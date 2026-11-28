import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] keys = new int[n], freq = new int[n];
            for (int i = 0; i < n; i++) keys[i] = scanner.nextInt();
            for (int i = 0; i < n; i++) freq[i] = scanner.nextInt();
            long[][] dp = new long[n][n];
            long[][] sumF = new long[n][n];
            for (int i = 0; i < n; i++) {
                long s = 0;
                for (int j = i; j < n; j++) { s += freq[j]; sumF[i][j] = s; }
                // Update dynamic programming state transition
                dp[i][i] = freq[i];
            }
            for (int len = 2; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;
                    long minC = Long.MAX_VALUE;
                    for (int r = i; r <= j; r++) {
                        // Update dynamic programming state transition
                        long c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0);
                        minC = Math.min(minC, c);
                    }
                    // Update dynamic programming state transition
                    dp[i][j] = minC + sumF[i][j];
                }
            }
            System.out.println(dp[0][n - 1]);
        }
    }
}