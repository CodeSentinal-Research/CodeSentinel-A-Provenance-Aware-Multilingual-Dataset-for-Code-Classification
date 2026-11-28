from typing import List
from collections import defaultdict

def eulerian_path(n: int, edges: List[List[int]]) -> List[int]:
    adj = defaultdict(list)
    deg = [0] * n
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
        deg[u] += 1
        deg[v] += 1

    odd = [i for i, d in enumerate(deg) if d % 2 != 0]
    if len(odd) not in (0, 2):
        return []

    start = odd[0] if len(odd) == 2 else 0
    edge_map = defaultdict(lambda: defaultdict(int))
    for u, v in edges:
        edge_map[u][v] += 1
        edge_map[v][u] += 1

    stack = [start]
    path = []
    while stack:
        u = stack[-1]
        has_edge = False
        for v in adj[u]:
            if edge_map[u][v] > 0:
                edge_map[u][v] -= 1
                edge_map[v][u] -= 1
                stack.append(v)
                has_edge = True
                break
        if not has_edge:
            path.append(stack.pop())
    return path[::-1]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    res = eulerian_path(n, edges)
    if res:
        print(" ".join(map(str, res)))
    else:
        print("NONE")