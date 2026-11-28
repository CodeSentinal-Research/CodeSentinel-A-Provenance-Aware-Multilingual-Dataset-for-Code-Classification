from typing import List
from collections import deque

def multi_source_bfs(n: int, edges: List[List[int]], sources: List[int]) -> List[int]:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    dist = [-1] * n
    q = deque()
    for s in sources:
        dist[s] = 0
        q.append(s)

    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist

if __name__ == '__main__':
    n, m, k = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    sources = list(map(int, input().split()))
    print(" ".join(map(str, multi_source_bfs(n, edges, sources))))