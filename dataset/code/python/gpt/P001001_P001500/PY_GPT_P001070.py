# problem title : Check Whether a Graph is Bipartite
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [0] * n
        for i in range(n):
            if color[i] == 0:
                q = deque([i])
                color[i] = 1
                while q:
                    u = q.popleft()
                    for v in graph[u]:
                        if color[v] == 0:
                            color[v] = -color[u]
                            q.append(v)
                        elif color[v] == color[u]:
                            return False
        return True
