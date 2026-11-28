from typing import List
import heapq

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])
        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = 0
        pq = [(0, 0, 0)]  # (effort, r, c)

        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while pq:
            d, r, c = heapq.heappop(pq)
            if r == m - 1 and c == n - 1:
                return d
            if d > dist[r][c]:
                continue
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    effort = max(d, abs(heights[nr][nc] - heights[r][c]))
                    if effort < dist[nr][nc]:
                        dist[nr][nc] = effort
                        heapq.heappush(pq, (effort, nr, nc))
        return 0