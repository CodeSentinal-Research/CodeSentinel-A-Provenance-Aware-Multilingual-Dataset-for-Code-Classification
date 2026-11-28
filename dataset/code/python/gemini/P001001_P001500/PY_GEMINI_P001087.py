from typing import List

def is_tree(n: int, edges: List[List[int]]) -> bool:
    if len(edges) != n - 1:
        return False
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    vis = [False] * n
    def dfs(u: int):
        vis[u] = True
        for v in adj[u]:
            if not vis[v]:
                dfs(v)

    dfs(0)
    return all(vis)

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print("YES" if is_tree(n, edges) else "NO")