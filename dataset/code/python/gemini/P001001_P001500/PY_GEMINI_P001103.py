from typing import List

class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        adj = [[] for _ in range(n)]
        for u, v in connections:
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
                        bridges.append([u, v])

        for i in range(n):
            if tin[i] == -1:
                dfs(i)
        return bridges