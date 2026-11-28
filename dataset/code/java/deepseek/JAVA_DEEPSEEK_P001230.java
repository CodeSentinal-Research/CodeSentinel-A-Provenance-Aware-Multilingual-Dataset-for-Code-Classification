import java.util.Scanner;

public class Main {
    private static int R, C, K;
    private static int[][] grid;
    private static int[][] dp;
    private static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        R = scanner.nextInt();
        C = scanner.nextInt();
        K = scanner.nextInt();

        grid = new int[R][C];
        dp = new int[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = scanner.nextInt();
                dp[i][j] = -1;
            }
        }

        int startX = scanner.nextInt();
        int startY = scanner.nextInt();

        System.out.println(getPaths(startX, startY));
    }

    private static int getPaths(int x, int y) {
        if (x < 0 || x >= R || y < 0 || y >= C) {
            return 1;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int ans = 0;
        for (int[] d : dir) {
            ans += getPaths(x + d[0], y + d[1]);
        }

        dp[x][y] = ans;
        return ans;
    }
}
