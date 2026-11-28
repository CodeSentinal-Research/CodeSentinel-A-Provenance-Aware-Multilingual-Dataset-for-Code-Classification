import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][] grid = new int[N][N];
        int[][] dp = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = scanner.nextInt();
                dp[i][j] = -1;
            }
        }
        System.out.println(maxCherries(grid, dp, N - 1, N - 1));
    }

    private static int maxCherries(int[][] grid, int[][] dp, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.length || y >= grid[0].length || grid[x][y] == -1) {
            return 0;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        if (x == 0 && y == 0) {
            return dp[x][y] = grid[x][y];
        }
        int cherries = grid[x][y];
        int right = maxCherries(grid, dp, x, y - 1);
        int down = maxCherries(grid, dp, x - 1, y);
        int rightDown = maxCherries(grid, dp, x - 1, y - 1);
        int cherriesInPath = cherries + Math.max(Math.max(right, down), rightDown);
        dp[x][y] = cherriesInPath;
        return dp[x][y];
    }
}
