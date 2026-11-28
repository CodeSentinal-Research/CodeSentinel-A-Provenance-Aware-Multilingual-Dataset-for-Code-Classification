import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] stones = new int[n];
        for (int i = 0; i < n; i++) {
            stones[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(minEnergy(stones));
    }

    private static int minEnergy(int[] stones) {
        int n = stones.length;
        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = Math.abs(stones[1] - stones[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.min(dp[i - 1], dp[i - 2]) + Math.abs(stones[i] - stones[i - 1]);
        }
        return Math.min(dp[n - 1], dp[n - 2]);
    }
}
