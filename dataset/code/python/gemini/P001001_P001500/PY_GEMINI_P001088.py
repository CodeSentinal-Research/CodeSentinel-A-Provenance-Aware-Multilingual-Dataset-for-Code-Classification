from typing import List
from collections import deque

def count_at_distance_k(n: int, edges: List[List[int]], src: int, k: int) -> int:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    dist = [-1] * n
    dist[src] = 0
    q = deque([src])

    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)

    return sum(1 for d in dist if d == k)

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    src, k = map(int, input().split())
    print(count_at_distance_k(n, edges, src, k))