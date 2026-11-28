import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLine()) {
            String s = sc.nextLine().trim();
            int n = s.length();
            long MOD = 1000000007;
            long[][] dp = new long[n][n];

            for (int i = 0; i < n; i++) dp[i][i] = 1;

            for (int len = 2; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;
                    if (s.charAt(i) == s.charAt(j)) {
                        // Update dynamic programming state transition
                        dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                    } else {
                        // Update dynamic programming state transition
                        dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                    }
                }
            }
            System.out.println(dp[0][n - 1]);
        }
        sc.close();
    }
}