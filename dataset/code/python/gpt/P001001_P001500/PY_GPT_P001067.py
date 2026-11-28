# problem title : Count Reachable Vertices
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def count_reachable(n: int, edges: List[List[int]], src: int) -> int:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)

    vis = [False] * n
    q = deque([src])
    vis[src] = True
    count = 0

    while q:
        u = q.popleft()
        count += 1
        for v in adj[u]:
            if not vis[v]:
                vis[v] = True
                q.append(v)
    return count

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    src = int(input())
    print(count_reachable(n, edges, src))
