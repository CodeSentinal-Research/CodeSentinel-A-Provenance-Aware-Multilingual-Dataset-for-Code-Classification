# problem title : Find All Bridges in a Graph
# Solve the stated task using standard input and standard output.
from typing import List

def find_bridges(n: int, edges: List[List[int]]) -> List[List[int]]:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    tin = [-1] * n
    low = [-1] * n
    timer = 0
    bridges = []

    def dfs(u: int, p: int = -1):
        nonlocal timer
        tin[u] = low[u] = timer
        timer += 1
        for v in adj[u]:
            if v == p:
                continue
            if tin[v] != -1:
                low[u] = min(low[u], tin[v])
            else:
                dfs(v, u)
                low[u] = min(low[u], low[v])
                if low[v] > tin[u]:
                    bridges.append([min(u, v), max(u, v)])

    for i in range(n):
        if tin[i] == -1:
            dfs(i)
    return sorted(bridges)

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    res = find_bridges(n, edges)
    for u, v in res:
        print(f"{u} {v}")
