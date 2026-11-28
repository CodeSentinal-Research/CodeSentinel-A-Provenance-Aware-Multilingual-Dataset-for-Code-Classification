from typing import List

def has_hamiltonian_path(n: int, edges: List[List[int]]) -> bool:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    vis = [False] * n

    def dfs(u: int, count: int) -> bool:
        if count == n:
            return True
        vis[u] = True
        for v in adj[u]:
            if not vis[v] and dfs(v, count + 1):
                return True
        vis[u] = False
        return False

    for i in range(n):
        if dfs(i, 1):
            return True
    return False

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print("YES" if has_hamiltonian_path(n, edges) else "NO")