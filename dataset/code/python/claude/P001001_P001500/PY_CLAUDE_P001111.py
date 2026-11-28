
from typing import List, Dict
from collections import deque

class Solution:
    def bfs(self, adj: Dict[int, List[int]], src: int) -> List[int]:
        visited = {src}
        queue = deque([src])
        result = []
        while queue:
            u = queue.popleft()
            result.append(u)
            for v in adj.get(u, []):
                if v not in visited:
                    visited.add(v)
                    queue.append(v)
        return result
