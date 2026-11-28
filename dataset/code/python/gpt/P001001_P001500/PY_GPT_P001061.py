# problem title : Detect Cycle in a Directed Graph
# Solve the stated task using standard input and standard output.
from typing import List

def has_cycle(n: int, edges: List[List[int]]) -> bool:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)

    vis = [0] * n  # 0=unvisited, 1=visiting, 2=visited

    def dfs(u: int) -> bool:
        vis[u] = 1
        for v in adj[u]:
            if vis[v] == 1:
                return True
            if vis[v] == 0 and dfs(v):
                return True
        vis[u] = 2
        return False

    for i in range(n):
        if vis[i] == 0:
            if dfs(i):
                return True
    return False

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print("YES" if has_cycle(n, edges) else "NO")
