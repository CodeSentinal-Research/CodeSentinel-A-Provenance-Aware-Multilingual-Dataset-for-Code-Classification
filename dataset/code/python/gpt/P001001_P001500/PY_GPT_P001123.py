# problem title : Find the City with the Smallest Number of Reachable Neighbors
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dist = [[float('inf')] * n for _ in range(n)]
        for i in range(n):
            dist[i][i] = 0
        for u, v, w in edges:
            dist[u][v] = dist[v][u] = w

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]

        min_reachable = float('inf')
        ans_city = -1
        for i in range(n):
            reachable = sum(1 for j in range(n) if i != j and dist[i][j] <= distanceThreshold)
            if reachable <= min_reachable:
                min_reachable = reachable
                ans_city = i
        return ans_city
