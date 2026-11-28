import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            int[][] grid = new int[m][n];
            Queue<int[]> q = new LinkedList<>();
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    grid[r][c] = scanner.nextInt();
                    if (grid[r][c] == 0) q.add(new int[]{r, c, 0});
                }
            }
            int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
            while (!q.isEmpty()) {
                int[] rm = q.poll();
                for (int i = 0; i < 4; i++) {
                    int nr = rm[0] + dr[i], nc = rm[1] + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 2147483647) {
                        grid[nr][nc] = rm[2] + 1;
                        q.add(new int[]{nr, nc, rm[2] + 1});
                    }
                }
            }
            for (int r = 0; r < m; r++) {
                StringBuilder sb = new StringBuilder();
                for (int c = 0; c < n; c++) {
                    sb.append(grid[r][c]).append(c == n - 1 ? "" : " ");
                }
                System.out.println(sb.toString());
            }
        }
    }
}