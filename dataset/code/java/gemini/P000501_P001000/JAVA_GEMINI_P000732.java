import java.util.*;
public class Solution {
    static int[] dr = {1, 0, 0, -1};
    static int[] dc = {0, -1, 1, 0};
    static char[] dname = {'D', 'L', 'R', 'U'};
    static void backtrack(int n, int r, int c, int[][] grid, boolean[][] vis, String path, List<String> res) {
        if (r == n - 1 && c == n - 1) {
            res.add(path);
            return;
        }
        vis[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]) {
                backtrack(n, nr, nc, grid, vis, path + dname[i], res);
            }
        }
        vis[r][c] = false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[][] grid = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) grid[i][j] = scanner.nextInt();
            }
            if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return;
            List<String> res = new ArrayList<>();
            backtrack(n, 0, 0, grid, new boolean[n][n], "", res);
            Collections.sort(res);
            for (String p : res) System.out.println(p);
        }
    }
}