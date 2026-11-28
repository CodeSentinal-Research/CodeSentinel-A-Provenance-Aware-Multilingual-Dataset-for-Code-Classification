import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] grid = new int[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) grid[i][j] = sc.nextInt();
        
        // BFS for fire spread
        int[][] fireTime = new int[m][n];
        for(int[] row : fireTime) Arrays.fill(row, Integer.MAX_VALUE);
        Queue<int[]> queue = new LinkedList<>();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    queue.offer(new int[]{i, j});
                    fireTime[i][j] = 0;
                }
            }
        }
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            for(int[] d : dirs) {
                int r = curr[0] + d[0], c = curr[1] + d[1];
                if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 2 && fireTime[r][c] == Integer.MAX_VALUE) {
                    fireTime[r][c] = fireTime[curr[0]][curr[1]] + 1;
                    queue.offer(new int[]{r, c});
                }
            }
        }
        
        // Binary search on wait time
        int low = 0, high = m * n, res = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canEscape(grid, fireTime, m, n, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println(res);
    }
    static boolean canEscape(int[][] grid, int[][] fireTime, int m, int n, int wait) {
        if(fireTime[0][0] <= wait) return false;
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        queue.offer(new int[]{0, 0, wait});
        visited[0][0] = true;
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0], c = curr[1], t = curr[2];
            if(r == m - 1 && c == n - 1) return true;
            for(int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] != 2) {
                    if(t + 1 < fireTime[nr][nc] || (nr == m - 1 && nc == n - 1 && t + 1 <= fireTime[nr][nc])) {
                        visited[nr][nc] = true;
                        queue.offer(new int[]{nr, nc, t + 1});
                    }
                }
            }
        }
        return false;
    }
}
