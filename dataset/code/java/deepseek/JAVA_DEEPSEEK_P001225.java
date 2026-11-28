import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        long[] dp = new long[N + 1];
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] * 2;
            dp[i] %= 1000000007;
        }

        System.out.println(dp[N]);
    }
}
