import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] houses = new int[n];
        for (int i = 0; i < n; i++) {
            houses[i] = scanner.nextInt();
        }
        System.out.println(rob(houses));
    }

    private static int rob(int[] houses) {
        int n = houses.length;
        if (n == 1) {
            return houses[0];
        }
        int[] dp = new int[n];
        dp[0] = houses[0];
        dp[1] = Math.max(houses[0], houses[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + houses[i]);
        }
        return dp[n - 1];
    }
}
