# problem title : Diameter of a Tree
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def tree_diameter(n: int, edges: List[List[int]]) -> int:
    if n <= 1:
        return 0
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    def bfs(src: int):
        dist = [-1] * n
        dist[src] = 0
        q = deque([src])
        farthest_node = src
        while q:
            u = q.popleft()
            for v in adj[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    q.append(v)
                    if dist[v] > dist[farthest_node]:
                        farthest_node = v
        return farthest_node, dist[farthest_node]

    u, _ = bfs(0)
    _, diam = bfs(u)
    return diam

if __name__ == '__main__':
    n = int(input())
    edges = [list(map(int, input().split())) for _ in range(n - 1)]
    print(tree_diameter(n, edges))
