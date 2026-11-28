import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[][] grid = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) grid[i][j] = scanner.nextInt();
            }
            Queue<int[]> q = new LinkedList<>();
            boolean[][][] vis = new boolean[n][n][2];
            q.add(new int[]{0, 0, 0, 0});
            vis[0][0][0] = true;
            int ans = -1;
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int r = cur[0], c = cur[1], s = cur[2], d = cur[3];
                if (s == 0 && r == n - 1 && c == n - 2) { ans = d; break; }
                if (s == 0) {
                    if (c + 2 < n && grid[r][c + 2] == 0 && !vis[r][c + 1][0]) {
                        vis[r][c + 1][0] = true; q.add(new int[]{r, c + 1, 0, d + 1});
                    }
                    if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r + 1][c][0]) {
                        vis[r + 1][c][0] = true; q.add(new int[]{r + 1, c, 0, d + 1});
                    }
                    if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][1]) {
                        vis[r][c][1] = true; q.add(new int[]{r, c, 1, d + 1});
                    }
                } else {
                    if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c + 1][1]) {
                        vis[r][c + 1][1] = true; q.add(new int[]{r, c + 1, 1, d + 1});
                    }
                    if (r + 2 < n && grid[r + 2][c] == 0 && !vis[r + 1][c][1]) {
                        vis[r + 1][c][1] = true; q.add(new int[]{r + 1, c, 1, d + 1});
                    }
                    if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][0]) {
                        vis[r][c][0] = true; q.add(new int[]{r, c, 0, d + 1});
                    }
                }
            }
            System.out.println(ans);
        }
    }
}