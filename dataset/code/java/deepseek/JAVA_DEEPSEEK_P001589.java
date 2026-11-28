import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] hours = new int[n];
        for (int i = 0; i < n; i++) {
            hours[i] = scanner.nextInt();
        }
        System.out.println(longestWellPerformingInterval(hours));
    }

    private static int longestWellPerformingInterval(int[] hours) {
        int n = hours.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        int max = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + (hours[i - 1] > 8 ? 1 : 0));
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
