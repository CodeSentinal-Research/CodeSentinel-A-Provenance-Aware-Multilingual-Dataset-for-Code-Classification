import java.util.Scanner;

public class Main {
    private static int N;
    private static int[][] maze;
    private static boolean[][] visited;
    private static StringBuilder path;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        scanner.nextLine();
        maze = new int[N][N];
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < N; j++) {
                maze[i][j] = line.charAt(j) - '0';
            }
        }
        path = new StringBuilder();
        dfs(0, 0);
        System.out.println(path.toString());
    }

    private static void dfs(int x, int y) {
        if (x == N - 1 && y == N - 1) {
            System.out.println(path.toString());
            return;
        }
        visited[x][y] = true;
        path.append((char) (y + 'a'));
        if (x + 1 < N && maze[x + 1][y] == 0 && !visited[x + 1][y]) {
            dfs(x + 1, y);
        }
        if (y + 1 < N && maze[x][y + 1] == 0 && !visited[x][y + 1]) {
            dfs(x, y + 1);
        }
        path.deleteCharAt(path.length() - 1);
        visited[x][y] = false;
    }
}
