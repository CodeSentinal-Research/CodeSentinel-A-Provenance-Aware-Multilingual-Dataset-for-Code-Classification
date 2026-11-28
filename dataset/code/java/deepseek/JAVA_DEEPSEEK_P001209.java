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

        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = stones[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Math.max(
                        stones[i] - dp[i + 1][j],
                        stones[j] - dp[i][j - 1]
                );
            }
        }

        int aliceScore = dp[0][n - 1];
        int bobScore = stones[0] + Math.min(stones[1], dp[1][n - 1]);

        if (aliceScore > bobScore) {
            System.out.println("Alice");
        } else if (aliceScore < bobScore) {
            System.out.println("Bob");
        } else {
            System.out.println("Tie");
        }
    }
}
