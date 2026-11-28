# problem title : Prim's Minimum Spanning Tree
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def prim_mst(n: int, edges: List[List[int]]) -> int:
    adj = [[] for _ in range(n)]
    for u, v, w in edges:
        adj[u].append((v, w))
        adj[v].append((u, w))

    vis = [False] * n
    pq = [(0, 0)]  # (weight, vertex)
    total_weight = 0

    while pq:
        w, u = heapq.heappop(pq)
        if vis[u]:
            continue
        vis[u] = True
        total_weight += w
        for v, weight in adj[u]:
            if not vis[v]:
                heapq.heappush(pq, (weight, v))

    return total_weight

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print(prim_mst(n, edges))
