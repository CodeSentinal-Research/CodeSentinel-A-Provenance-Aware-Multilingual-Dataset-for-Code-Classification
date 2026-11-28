import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        long[][] dp = new long[N + 1][K + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= K; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
            }
        }
        System.out.println(dp[N][K]);
    }
}
