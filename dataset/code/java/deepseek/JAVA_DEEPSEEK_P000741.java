import java.util.*;

public class Main {
    private static int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private static int[][] grid;
    private static int N, M;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        List<String> paths = new ArrayList<>();
        dfs(0, 0, "", paths);
        Collections.sort(paths);
        for (String path : paths) {
            System.out.println(path);
        }
    }

    private static void dfs(int x, int y, String path, List<String> paths) {
        if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] == 0) {
            return;
        }
        if (x == N - 1 && y == M - 1) {
            paths.add(path);
            return;
        }
        grid[x][y] = 0;
        for (int[] dir : directions) {
            dfs(x + dir[0], y + dir[1], path + (char)('A' + dir[0] + dir[1]), paths);
        }
        grid[x][y] = 1;
    }
}
