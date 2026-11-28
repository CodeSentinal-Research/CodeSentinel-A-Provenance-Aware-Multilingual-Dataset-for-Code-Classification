# problem title : Network Delay Time
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = [[] for _ in range(n + 1)]
        for u, v, w in times:
            adj[u].append((v, w))

        dist = [float('inf')] * (n + 1)
        dist[k] = 0
        pq = [(0, k)]

        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))

        ans = max(dist[1:])
        return ans if ans != float('inf') else -1
