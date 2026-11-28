import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        int[][] gold = new int[R][C];
        int[][] dp = new int[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                gold[i][j] = scanner.nextInt();
            }
        }

        dp[0][0] = gold[0][0];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + gold[i][j]);
                }
                if (j > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j - 1] + gold[i][j]);
                }
                if (i < R - 1) {
                    dp[i][j] = Math.max(dp[i][j], dp[i + 1][j] + gold[i][j]);
                }
                if (j < C - 1) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j + 1] + gold[i][j]);
                }
            }
        }

        System.out.println(dp[R - 1][C - 1]);
    }
}
