# problem title : Strongly Connected Components Count
# Solve the stated task using standard input and standard output.
from typing import List

def count_scc(n: int, edges: List[List[int]]) -> int:
    adj = [[] for _ in range(n)]
    radj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        radj[v].append(u)

    vis = [False] * n
    order = []

    def dfs1(u: int):
        vis[u] = True
        for v in adj[u]:
            if not vis[v]:
                dfs1(v)
        order.append(u)

    for i in range(n):
        if not vis[i]:
            dfs1(i)

    vis = [False] * n
    scc_count = 0

    def dfs2(u: int):
        vis[u] = True
        for v in radj[u]:
            if not vis[v]:
                dfs2(v)

    for u in reversed(order):
        if not vis[u]:
            dfs2(u)
            scc_count += 1
    return scc_count

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print(count_scc(n, edges))
