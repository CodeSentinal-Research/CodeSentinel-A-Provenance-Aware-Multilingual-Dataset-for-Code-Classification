import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] stones = new int[N];
        for (int i = 0; i < N; i++) {
            stones[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(minEnergy(stones, N, K));
    }

    private static int minEnergy(int[] stones, int N, int K) {
        int[] dp = new int[N];
        for (int i = 1; i < N; i++) {
            dp[i] = dp[i - 1] + Math.abs(stones[i] - stones[i - 1]);
            if (i - K >= 0) {
                dp[i] = Math.min(dp[i], dp[i - K - 1] + Math.abs(stones[i] - stones[i - K - 1]));
            }
        }
        return dp[N - 1];
    }
}
