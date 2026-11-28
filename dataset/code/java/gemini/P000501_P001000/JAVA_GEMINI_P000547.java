import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            int[][] grid = new int[m][n];
            int[][] fireTime = new int[m][n];
            for (int[] row : fireTime) Arrays.fill(row, (int)1e9);
            Queue<int[]> fireQ = new LinkedList<>();
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    grid[r][c] = scanner.nextInt();
                    if (grid[r][c] == 1) {
                        fireQ.add(new int[]{r, c, 0});
                        fireTime[r][c] = 0;
                    }
                }
            }
            int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
            while (!fireQ.isEmpty()) {
                int[] s = fireQ.poll();
                for (int i = 0; i < 4; i++) {
                    int nr = s[0] + dr[i], nc = s[1] + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && fireTime[nr][nc] == (int)1e9) {
                        fireTime[nr][nc] = s[2] + 1;
                        fireQ.add(new int[]{nr, nc, s[2] + 1});
                    }
                }
            }
            int low = 0, high = (int)1e9, ans = -1;
            // Binary search loop to narrow down range
            while (low <= high) {
                // Calculate midpoint to prevent potential overflow
                int mid = low + (high - low) / 2;
                if (canEscape(grid, fireTime, m, n, mid, dr, dc)) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            System.out.println(ans);
        }
    }
    static boolean canEscape(int[][] grid, int[][] fireTime, int m, int n, int wait, int[] dr, int[] dc) {
        if (fireTime[0][0] <= wait) return false;
        Queue<int[]> q = new LinkedList<>();
        boolean[][] vis = new boolean[m][n];
        q.add(new int[]{0, 0, wait});
        vis[0][0] = true;
        while (!q.isEmpty()) {
            int[] s = q.poll();
            if (s[0] == m - 1 && s[1] == n - 1) return true;
            for (int i = 0; i < 4; i++) {
                int nr = s[0] + dr[i], nc = s[1] + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && !vis[nr][nc]) {
                    if (nr == m - 1 && nc == n - 1) {
                        if (s[2] + 1 <= fireTime[nr][nc]) return true;
                    } else if (s[2] + 1 < fireTime[nr][nc]) {
                        vis[nr][nc] = true;
                        q.add(new int[]{nr, nc, s[2] + 1});
                    }
                }
            }
        }
        return false;
    }
}