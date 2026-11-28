import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        int[][] grid = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        System.out.println(minPathSum(grid, R, C));
    }

    public static int minPathSum(int[][] grid, int R, int C) {
        int[][] dp = new int[R][C];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < R; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < C; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[R - 1][C - 1];
    }
}
