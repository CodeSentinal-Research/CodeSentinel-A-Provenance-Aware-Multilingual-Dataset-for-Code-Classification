import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        long[][] dp = new long[R][C];
        for (int i = 0; i < R; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < C; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        System.out.println(dp[R - 1][C - 1]);
    }
}
