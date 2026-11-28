from typing import List

def has_hamiltonian_cycle(n: int, edges: List[List[int]]) -> bool:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    vis = [False] * n

    def dfs(u: int, count: int) -> bool:
        if count == n:
            return 0 in adj[u]
        vis[u] = True
        for v in adj[u]:
            if not vis[v] and dfs(v, count + 1):
                return True
        vis[u] = False
        return False

    return dfs(0, 1)

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print("YES" if has_hamiltonian_cycle(n, edges) else "NO")