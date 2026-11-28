# problem title : Minimum Cut
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def min_cut(n: int, edges: List[List[int]], src: int, sink: int) -> int:
    cap = [[0] * n for _ in range(n)]
    for u, v, c in edges:
        cap[u][v] += c

    while True:
        parent = [-1] * n
        parent[src] = -2
        q = deque([src])
        aug = 0
        cur_cap = {src: float('inf')}
        while q:
            u = q.popleft()
            if u == sink:
                aug = cur_cap[u]
                break
            for v in range(n):
                if parent[v] == -1 and cap[u][v] > 0:
                    parent[v] = u
                    cur_cap[v] = min(cur_cap[u], cap[u][v])
                    q.append(v)
        if parent[sink] == -1:
            break
        curr = sink
        while curr != src:
            p = parent[curr]
            cap[p][curr] -= aug
            cap[curr][p] += aug
            curr = p

    # BFS from src in residual graph
    vis = [False] * n
    vis[src] = True
    q = deque([src])
    while q:
        u = q.popleft()
        for v in range(n):
            if not vis[v] and cap[u][v] > 0:
                vis[v] = True
                q.append(v)

    min_cut_val = 0
    for u, v, c in edges:
        if vis[u] and not vis[v]:
            min_cut_val += c
    return min_cut_val

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    src, sink = map(int, input().split())
    print(min_cut(n, edges, src, sink))
