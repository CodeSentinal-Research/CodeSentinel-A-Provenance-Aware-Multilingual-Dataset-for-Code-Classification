import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] piles = new int[n];
        for (int i = 0; i < n; i++) {
            piles[i] = scanner.nextInt();
        }
        System.out.println(canWinStones(piles) ? "YES" : "NO");
    }

    private static boolean canWinStones(int[] piles) {
        int n = piles.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = piles[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = Math.max(piles[i - 1] - dp[i - 1], piles[i - 2] - dp[i - 2]);
        }
        return dp[n] > 0;
    }
}
