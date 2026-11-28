# problem title : Reachability Queries
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def reachability_queries(n: int, edges: List[List[int]], queries: List[List[int]]) -> List[str]:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)

    res = []
    for src, dst in queries:
        vis = [False] * n
        vis[src] = True
        q = deque([src])
        found = False
        while q:
            u = q.popleft()
            if u == dst:
                found = True
                break
            for v in adj[u]:
                if not vis[v]:
                    vis[v] = True
                    q.append(v)
        res.append("YES" if found else "NO")
    return res

if __name__ == '__main__':
    n, m, q = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    queries = [list(map(int, input().split())) for _ in range(q)]
    for ans in reachability_queries(n, edges, queries):
        print(ans)
