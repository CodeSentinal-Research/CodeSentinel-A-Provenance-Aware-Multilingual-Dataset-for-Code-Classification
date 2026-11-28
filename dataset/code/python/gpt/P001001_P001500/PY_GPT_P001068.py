# problem title : Topological Sorting
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def topological_sort(n: int, edges: List[List[int]]) -> List[int]:
    adj = [[] for _ in range(n)]
    in_deg = [0] * n
    for u, v in edges:
        adj[u].append(v)
        in_deg[v] += 1

    q = deque([i for i in range(n) if in_deg[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            in_deg[v] -= 1
            if in_deg[v] == 0:
                q.append(v)
    return order if len(order) == n else []

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    res = topological_sort(n, edges)
    print(" ".join(map(str, res)))
