import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int amount = scanner.nextInt();
        int[] denominations = new int[n];
        for (int i = 0; i < n; i++) {
            denominations[i] = scanner.nextInt();
        }
        System.out.println(countWays(denominations, n, amount));
    }

    private static int countWays(int[] denominations, int n, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = denominations[i]; j <= amount; j++) {
                dp[j] += dp[j - denominations[i]];
            }
        }
        return dp[amount];
    }
}
