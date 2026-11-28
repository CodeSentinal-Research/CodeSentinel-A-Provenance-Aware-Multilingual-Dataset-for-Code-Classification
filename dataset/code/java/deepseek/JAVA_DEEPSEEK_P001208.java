import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] piles = new int[n];
        for (int i = 0; i < n; i++) {
            piles[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(getMaxStones(piles, n));
    }

    private static int getMaxStones(int[] piles, int n) {
        int[][] dp = new int[n][n];
        int[] sum = new int[n];
        sum[0] = piles[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + piles[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Math.max(sum[j] - sum[i] - dp[i + 1][j], sum[j - 1] - sum[i - 1] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
}
