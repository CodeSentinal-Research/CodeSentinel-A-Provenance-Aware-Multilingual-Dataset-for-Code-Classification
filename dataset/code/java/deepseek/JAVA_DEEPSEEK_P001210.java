import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] coins = new int[n];
        for (int i = 0; i < n; i++) {
            coins[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxCoins(coins, n));
    }

    private static int maxCoins(int[] coins, int n) {
        int[][] dp = new int[n][n];
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = coins[i];
                } else if (gap == 1) {
                    dp[i][j] = Math.max(coins[i], coins[j]);
                } else {
                    dp[i][j] = Math.max(coins[i] + dp[i + 1][j], coins[j] + dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
