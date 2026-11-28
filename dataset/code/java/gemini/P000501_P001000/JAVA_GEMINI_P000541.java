import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            int[][] grid = new int[m][n];
            Queue<int[]> q = new LinkedList<>();
            int fresh = 0;
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    grid[r][c] = scanner.nextInt();
                    if (grid[r][c] == 2) q.add(new int[]{r, c, 0});
                    else if (grid[r][c] == 1) fresh++;
                }
            }
            int mins = 0;
            int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
            while (!q.isEmpty()) {
                int[] o = q.poll();
                mins = Math.max(mins, o[2]);
                for (int i = 0; i < 4; i++) {
                    int nr = o[0] + dr[i], nc = o[1] + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.add(new int[]{nr, nc, o[2] + 1});
                    }
                }
            }
            System.out.println(fresh == 0 ? mins : -1);
        }
    }
}