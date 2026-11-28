import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] cost = new int[n];
        for (int i = 0; i < n; i++) {
            cost[i] = scanner.nextInt();
        }
        System.out.println(minCostClimbingStairs(cost));
    }

    public static int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length + 1];
        dp[0] = dp[1] = 0;
        for (int i = 1; i < cost.length; i++) {
            dp[i + 1] = Math.min(dp[i], dp[i - 1]) + cost[i];
        }
        return Math.min(dp[cost.length], dp[cost.length - 1]);
    }
}
