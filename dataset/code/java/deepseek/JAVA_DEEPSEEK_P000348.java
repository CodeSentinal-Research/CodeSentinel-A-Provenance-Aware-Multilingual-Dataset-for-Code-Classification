import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(checkRecord(n));
    }

    public static int checkRecord(int n) {
        long MOD = 1_000_000_007;
        long[] P = new long[n+5];
        long[][] dp = new long[n+5][6];

        P[0] = 1;
        for (int i = 1; i <= n; i++) {
            P[i] = P[i-1] * 2 % MOD;
            if (i-3 >= 0) P[i] = (P[i] + MOD - P[i-3]) % MOD;
        }

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5]) % MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
            dp[i][3] = (dp[i-1][0]) % MOD;
            dp[i][4] = (dp[i-1][1]) % MOD;
            dp[i][5] = (dp[i-1][2]) % MOD;
            for (int j = 0; j < 6; j++) {
                if (i-2 >= 0) dp[i][j] = (dp[i][j] + MOD - dp[i-2][j]) % MOD;
            }
        }

        long ans = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5]) % MOD;
        for (int i = 0; i < n; i++) {
            ans = (ans + MOD - P[i] * (dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3] + dp[i][4] + dp[i][5]) % MOD) % MOD;
        }

        return (int)ans;
    }
}
