import java.util.Scanner;

public class Main {
    private static int[][] grid;
    private static int[][] dp;
    private static int n, m, target;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        target = scanner.nextInt();

        grid = new int[n][m];
        dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }

        dp[n - 1][m - 1] = grid[n - 1][m - 1] == target ? 1 : 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) continue;
                dp[i][j] = (i < n - 1 ? dp[i + 1][j] : 0) + (j < m - 1 ? dp[i][j + 1] : 0) + dp[i][j];
                if (grid[i][j] == target) {
                    dp[i][j]--;
                }
            }
        }

        System.out.println(dp[0][0]);
    }
}
