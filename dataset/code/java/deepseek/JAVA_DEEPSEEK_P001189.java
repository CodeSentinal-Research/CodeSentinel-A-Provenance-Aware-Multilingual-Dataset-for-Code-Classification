import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        System.out.println(maxProfit(prices, k));
    }

    public static int maxProfit(int[] prices, int k) {
        int n = prices.length;
        if (n < 2 || k < 1) {
            return 0;
        }
        int[][] dp = new int[k+1][n+1];
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= k; i++) {
            int max = -prices[0];
            for (int j = 1; j <= n; j++) {
                max = Math.max(max, dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = Math.max(dp[i][j-1], max + prices[j-1]);
            }
        }
        return dp[k][n];
    }
}
