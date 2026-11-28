import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] piles = new int[n];
        for (int i = 0; i < n; i++) {
            piles[i] = scanner.nextInt();
        }
        System.out.println(stoneGameII(piles));
    }

    public static int stoneGameII(int[] piles) {
        int n = piles.length;
        int[] suffixSum = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = suffixSum[i];
            for (int x = 1; x <= 2 && i + 2 * x <= n; x++) {
                dp[i] = Math.max(dp[i], suffixSum[i] - dp[i + x]);
            }
       }
        return dp[0];
    }
}
