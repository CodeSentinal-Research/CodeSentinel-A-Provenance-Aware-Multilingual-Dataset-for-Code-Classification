import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] balloons = new int[n + 2];
        for (int i = 0; i < n; i++) {
            balloons[i] = scanner.nextInt();
        }
        System.out.println(burstBalloons(balloons, n));
    }

    private static int burstBalloons(int[] balloons, int n) {
        int[] dp = new int[n + 2];
        dp[0] = 0;
        dp[n + 1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = Math.max(dp[i], dp[i - 1] + balloons[i - 1] * balloons[i] * balloons[i + 1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = Math.max(dp[i], dp[i + 1] + balloons[i] * balloons[i + 1] * balloons[i + 2]);
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, dp[i + 1]);
        }
        return max;
    }
}
