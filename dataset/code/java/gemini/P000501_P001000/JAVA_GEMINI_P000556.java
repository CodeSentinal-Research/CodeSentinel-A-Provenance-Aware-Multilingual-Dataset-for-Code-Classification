import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            int[][] grid = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) grid[i][j] = scanner.nextInt();
            }
            if (m == 1 && n == 1) { System.out.println(1); return; }
            int[][] dist = new int[m][n];
            for (int[] row : dist) Arrays.fill(row, (int)1e9);
            dist[0][0] = 1;
            int[] maxR = new int[m], maxC = new int[n];
            Queue<int[]> q = new LinkedList<>();
            q.add(new int[]{0, 0});
            while (!q.isEmpty()) {
                int[] p = q.poll();
                int r = p[0], c = p[1], d = dist[r][c], k = grid[r][c];
                int startC = Math.max(c + 1, maxR[r] + 1);
                int endC = Math.min(c + k, n - 1);
                for (int nc = startC; nc <= endC; nc++) {
                    if (dist[r][nc] == (int)1e9) {
                        dist[r][nc] = d + 1;
                        if (r == m - 1 && nc == n - 1) { System.out.println(d + 1); return; }
                        q.add(new int[]{r, nc});
                    }
                }
                maxR[r] = Math.max(maxR[r], endC);
                int startR = Math.max(r + 1, maxC[c] + 1);
                int endR = Math.min(r + k, m - 1);
                for (int nr = startR; nr <= endR; nr++) {
                    if (dist[nr][c] == (int)1e9) {
                        dist[nr][c] = d + 1;
                        if (nr == m - 1 && c == n - 1) { System.out.println(d + 1); return; }
                        q.add(new int[]{nr, c});
                    }
                }
                maxC[c] = Math.max(maxC[c], endR);
            }
            System.out.println(dist[m - 1][n - 1] != (int)1e9 ? dist[m - 1][n - 1] : -1);
        }
    }
}