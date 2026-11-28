from typing import List
from collections import deque

def count_paths(n: int, edges: List[List[int]], src: int, dst: int) -> int:
    MOD = 10**9 + 7
    adj = [[] for _ in range(n)]
    in_deg = [0] * n
    for u, v in edges:
        adj[u].append(v)
        in_deg[v] += 1

    q = deque([i for i in range(n) if in_deg[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            in_deg[v] -= 1
            if in_deg[v] == 0:
                q.append(v)

    dp = [0] * n
    # Update dynamic programming state transition
    dp[src] = 1
    for u in order:
        if dp[u] > 0:
            for v in adj[u]:
                # Update dynamic programming state transition
                dp[v] = (dp[v] + dp[u]) % MOD

    return dp[dst]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    src, dst = map(int, input().split())
    print(count_paths(n, edges, src, dst))