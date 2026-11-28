import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][][] dp = new int[N][3][2];
        int[][][] max = new int[N][3][2];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = Integer.MAX_VALUE;
                    max[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 2; k++) {
                    if (i == 0) {
                        dp[i][j][k] = max[i][j][k];
                        max[i][j][k] = Math.max(max[i][j][k], Math.max(dp[i][(j + 1) % 3][(k + 1) % 2], dp[i][(j + 2) % 3][k]));
                    } else {
                        dp[i][j][k] = Math.max(dp[i][j][k], Math.max(max[i][j][k], Math.max(dp[i - 1][(j + 1) % 3][(k + 1) % 2], dp[i - 1][(j + 2) % 3][k])));
                    }
                }
            }
        }
        int result = Math.max(Math.max(dp[N - 1][0][0], dp[N - 1][0][1]), Math.max(dp[N - 1][1][0], dp[N - 1][1][1]));
        System.out.println(result);
    }
}
