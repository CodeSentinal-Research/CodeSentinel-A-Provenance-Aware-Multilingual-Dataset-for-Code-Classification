# problem title : M-Coloring Problem
# Solve the stated task using standard input and standard output.
from typing import List

def m_coloring(n: int, edges: List[List[int]], m: int) -> bool:
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    color = [0] * n

    def is_safe(u: int, c: int) -> bool:
        for v in adj[u]:
            if color[v] == c:
                return False
        return True

    def solve(u: int) -> bool:
        if u == n:
            return True
        for c in range(1, m + 1):
            if is_safe(u, c):
                color[u] = c
                if solve(u + 1):
                    return True
                color[u] = 0
        return False

    return solve(0)

if __name__ == '__main__':
    n, num_edges, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(num_edges)]
    print("YES" if m_coloring(n, edges, m) else "NO")
