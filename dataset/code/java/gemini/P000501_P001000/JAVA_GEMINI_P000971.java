import java.util.Scanner;

public class Solution {
    private static final long MOD = 1000000007L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int k = sc.nextInt();
            int n = sc.nextInt();
            long[] coeffs = new long[k];
            for (int i = 0; i < k; i++) coeffs[i] = sc.nextLong();
            long[] dp = new long[Math.max(k, n + 1)];
            for (int i = 0; i < k; i++) dp[i] = sc.nextLong();
            for (int i = k; i <= n; i++) {
                long val = 0;
                for (int j = 0; j < k; j++) {
                    // Update dynamic programming state transition
                    val = (val + coeffs[j] * dp[i - 1 - j]) % MOD;
                }
                // Update dynamic programming state transition
                dp[i] = val;
            }
            System.out.println((dp[n] % MOD + MOD) % MOD);
        }
        sc.close();
    }
}