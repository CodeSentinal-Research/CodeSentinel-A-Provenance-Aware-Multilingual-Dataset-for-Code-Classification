# problem title : Find All Articulation Points
# Solve the stated task using standard input and standard output.
from typing import List

def find_articulation_points(n: int, edges: List[List[int]]) -> List[int]:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    tin = [-1] * n
    low = [-1] * n
    timer = 0
    is_ap = [False] * n

    def dfs(u: int, p: int = -1):
        nonlocal timer
        tin[u] = low[u] = timer
        timer += 1
        children = 0
        for v in adj[u]:
            if v == p:
                continue
            if tin[v] != -1:
                low[u] = min(low[u], tin[v])
            else:
                dfs(v, u)
                low[u] = min(low[u], low[v])
                if low[v] >= tin[u] and p != -1:
                    is_ap[u] = True
                children += 1
        if p == -1 and children > 1:
            is_ap[u] = True

    for i in range(n):
        if tin[i] == -1:
            dfs(i)

    return [i for i in range(n) if is_ap[i]]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    res = find_articulation_points(n, edges)
    print(" ".join(map(str, res)))
