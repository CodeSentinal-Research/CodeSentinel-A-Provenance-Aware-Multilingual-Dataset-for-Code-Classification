# problem title : Eventual Safe States
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        color = [0] * n  # 0: unvisited, 1: visiting, 2: safe

        def dfs(u: int) -> bool:
            color[u] = 1
            for v in graph[u]:
                if color[v] == 1 or (color[v] == 0 and not dfs(v)):
                    return False
            color[u] = 2
            return True

        return [i for i in range(n) if color[i] == 2 or (color[i] == 0 and dfs(i))]
