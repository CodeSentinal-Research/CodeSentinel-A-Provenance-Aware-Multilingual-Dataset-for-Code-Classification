from typing import List

def graph_coloring(adj: List[List[int]], m: int, v: int) -> bool:
    color = [0] * v

    def is_safe(node: int, c: int) -> bool:
        for neighbor in range(v):
            if adj[node][neighbor] == 1 and color[neighbor] == c:
                return False
        return True

    def solve(node: int) -> bool:
        """Solves 'M-Coloring Problem' by applying optimal Backtracking logic."""
        if node == v:
            return True
        for c in range(1, m + 1):
            if is_safe(node, c):
                color[node] = c
                if solve(node + 1):
                    return True
                color[node] = 0
        return False

    return solve(0)

if __name__ == '__main__':
    v, m, e = map(int, input().split())
    adj = [[0] * v for _ in range(v)]
    for _ in range(e):
        u, w = map(int, input().split())
        adj[u][w] = 1
        adj[w][u] = 1
    print(1 if graph_coloring(adj, m, v) else 0)