import java.util.Scanner;

public class Main {
    private static int R, C;
    private static int[][] grid;
    private static boolean[][] visited;
    private static int maxGold;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        R = scanner.nextInt();
        C = scanner.nextInt();
        scanner.nextLine();

        grid = new int[R][C];
        visited = new boolean[R][C];
        maxGold = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = scanner.nextInt();
            }
            scanner.nextLine();
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                visited[i][j] = true;
                maxGold = Math.max(maxGold, dfs(i, j));
                visited[i][j] = false;
            }
        }

        System.out.println(maxGold);
    }

    private static int dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= R || c >= C || visited[r][c] || grid[r][c] == 0) {
            return 0;
        }

        visited[r][c] = true;
        int gold = grid[r][c];
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int[] dir : dirs) {
            gold += dfs(r + dir[0], c + dir[1]);
        }
        visited[r][c] = false;

        return gold;
    }
}
