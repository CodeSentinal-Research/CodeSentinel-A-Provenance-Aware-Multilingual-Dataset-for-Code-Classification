import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        System.out.println(distributeBalls(N, K));
    }

    private static long distributeBalls(int N, int K) {
        long[][] dp = new long[N + 1][K + 1];
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= K; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                if (j < i) {
                    dp[i][j] -= dp[i - 1][j - 1];
                }
            }
        }
        return dp[N][K];
    }
}
