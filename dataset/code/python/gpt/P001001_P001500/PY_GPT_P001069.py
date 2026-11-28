# problem title : Shortest Path in a Directed Acyclic Graph
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def shortest_path_dag(n: int, edges: List[List[int]], src: int) -> List[int]:
    adj = [[] for _ in range(n)]
    in_deg = [0] * n
    for u, v, w in edges:
        adj[u].append((v, w))
        in_deg[v] += 1

    q = deque([i for i in range(n) if in_deg[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v, w in adj[u]:
            in_deg[v] -= 1
            if in_deg[v] == 0:
                q.append(v)

    dist = [float('inf')] * n
    dist[src] = 0
    for u in order:
        if dist[u] != float('inf'):
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

    return [int(d) if d != float('inf') else -1 for d in dist]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    src = int(input())
    print(" ".join(map(str, shortest_path_dag(n, edges, src))))
