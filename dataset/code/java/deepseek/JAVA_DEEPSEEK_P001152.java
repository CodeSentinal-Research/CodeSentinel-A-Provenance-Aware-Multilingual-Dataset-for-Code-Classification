import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(countPS(s));
    }

    static long countPS(String str) {
        int n = str.length();
        long[][] dp = new long[n][n];

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < n - 1; i++) {
            if (str.charAt(i) == str.charAt(i + 1)) {
                dp[i][i + 1] = dp[i + 1][i + 1] + dp[i][i] + dp[i + 1][i] + 1;
            } else {
                dp[i][i + 1] = dp[i + 1][i + 1] + dp[i][i] + dp[i + 1][i] - dp[i + 1][i + 1];
            }
        }

        for (int gap = 2; gap < n; gap++) {
            for (int i = 0, k = gap + i; k < n; i++, k++) {
                if (str.charAt(i) == str.charAt(k)) {
                    dp[i][k] = dp[i][k - 1] + dp[i + 1][k] + dp[i + 1][k - 1] + 1;
                } else {
                    dp[i][k] = dp[i][k - 1] + dp[i + 1][k] + dp[i + 1][k - 1] - dp[i + 1][k];
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i][n - 1];
        }

        return ans;
    }
}
