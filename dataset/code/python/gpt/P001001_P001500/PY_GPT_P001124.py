# problem title : Cheapest Flight Within K Stops
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dist = [float('inf')] * n
        dist[src] = 0

        for _ in range(k + 1):
            tmp = list(dist)
            for u, v, w in flights:
                if dist[u] != float('inf') and dist[u] + w < tmp[v]:
                    tmp[v] = dist[u] + w
            dist = tmp

        return dist[dst] if dist[dst] != float('inf') else -1
