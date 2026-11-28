import java.util.*;

public class Solution {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int[][] dist = new int[m][n];
        for (int i = 0; i < m; i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
        dist[0][0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0], r = cur[1], c = cur[2];
            if (r == m - 1 && c == n - 1) return d;
            if (d > dist[r][c]) continue;
            for (int[] dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int effort = Math.max(d, Math.abs(heights[nr][nc] - heights[r][c]));
                    if (effort < dist[nr][nc]) {
                        dist[nr][nc] = effort;
                        pq.offer(new int[]{effort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
}