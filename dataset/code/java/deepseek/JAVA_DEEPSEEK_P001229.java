import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int C = scanner.nextInt();

        double[][] dp = new double[N + 1][K + 1];
        dp[R][0] = 1;

        for (int i = 1; i <= K; i++) {
            for (int j = 0; j < N; j++) {
                dp[j][i] = dp[j][i - 1] * (N - j) / N;
                if (j > 0) {
                    dp[j][i] += dp[j - 1][i - 1] * (j - 1) / (N - 1);
                }
                if (j < N - 1) {
                    dp[j][i] += dp[j + 1][i - 1] * (N - j - 1) / (N - 1);
                }
            }
        }

        double probability = 0;
        for (int i = 0; i < N; i++) {
            probability += dp[i][K];
        }

        System.out.printf("%.10f", probability);
    }
}
