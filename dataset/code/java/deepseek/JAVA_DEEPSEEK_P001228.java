import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int d = scanner.nextInt();
        int f = scanner.nextInt();
        int s = scanner.nextInt();

        int[][][] dp = new int[d + 1][f + 1][s + 1];

        for (int i = 0; i <= d; i++) {
            for (int j = 0; j <= f; j++) {
                dp[i][j][0] = 1;
            }
        }

        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= f; j++) {
                for (int k = 1; k <= s; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j > 1) {
                        dp[i][j][k] += dp[i][j - 1][k];
                    }
                    if (k > 1) {
                        dp[i][j][k] += dp[i][j][k - 1];
                    }
                    if (i > 1) {
                        dp[i][j][k] += dp[i - 1][j][k];
                    }
                    dp[i][j][k] %= 1000000007;
                }
            }
        }

        System.out.println(dp[d][f][s]);
    }
}
