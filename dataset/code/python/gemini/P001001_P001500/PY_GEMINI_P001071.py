from typing import List

def find_mother_vertex(n: int, edges: List[List[int]]) -> int:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)

    vis = [False] * n
    last_v = 0

    def dfs(u: int):
        vis[u] = True
        for v in adj[u]:
            if not vis[v]:
                dfs(v)

    for i in range(n):
        if not vis[i]:
            dfs(i)
            last_v = i

    vis = [False] * n
    dfs(last_v)
    return last_v if all(vis) else -1

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print(find_mother_vertex(n, edges))