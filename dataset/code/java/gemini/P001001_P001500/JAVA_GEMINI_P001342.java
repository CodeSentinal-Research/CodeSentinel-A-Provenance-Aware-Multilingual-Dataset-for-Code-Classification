import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            long MOD = 1000000007;
            long[][] dp = new long[n][k + 1];

            for (int i = 0; i < n; i++) dp[i][1] = 1;

            for (int len = 2; len <= k; len++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < i; j++) {
                        if (arr[j] < arr[i]) {
                            // Update dynamic programming state transition
                            dp[i][len] = (dp[i][len] + dp[j][len - 1]) % MOD;
                        }
                    }
                }
            }

            long ans = 0;
            for (int i = 0; i < n; i++) ans = (ans + dp[i][k]) % MOD;
            System.out.println(ans);
        }
        sc.close();
    }
}