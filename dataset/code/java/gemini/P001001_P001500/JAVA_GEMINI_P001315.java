import java.util.*;

public class Solution {
    private static List<String> res = new ArrayList<>();
    private static int[][] dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    private static char[] dirChars = {'D', 'L', 'R', 'U'};

    private static void backtrack(int r, int c, int n, int[][] maze, boolean[][] visited, StringBuilder path) {
        if (r == n - 1 && c == n - 1) {
            res.add(path.toString());
            return;
        }

        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0], nc = c + dirs[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && maze[nr][nc] == 1) {
                path.append(dirChars[i]);
                backtrack(nr, nc, n, maze, visited, path);
                path.deleteCharAt(path.length() - 1);
            }
        }
        visited[r][c] = false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] maze = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) maze[i][j] = sc.nextInt();
            }

            if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
                boolean[][] visited = new boolean[n][n];
                backtrack(0, 0, n, maze, visited, new StringBuilder());
            }

            if (res.isEmpty()) System.out.println("-1");
            else System.out.println(String.join(" ", res));
        }
        sc.close();
    }
}