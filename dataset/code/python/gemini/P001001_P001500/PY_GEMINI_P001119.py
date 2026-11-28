from typing import List
from collections import defaultdict, deque

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(dict)
        for (a, b), val in zip(equations, values):
            graph[a][b] = val
            graph[b][a] = 1.0 / val

        def bfs(src: str, dst: str) -> float:
            if src not in graph or dst not in graph:
                return -1.0
            if src == dst:
                return 1.0
            q = deque([(src, 1.0)])
            visited = {src}
            while q:
                node, prod = q.popleft()
                if node == dst:
                    return prod
                for nxt, weight in graph[node].items():
                    if nxt not in visited:
                        visited.add(nxt)
                        q.append((nxt, prod * weight))
            return -1.0

        return [bfs(q[0], q[1]) for q in queries]