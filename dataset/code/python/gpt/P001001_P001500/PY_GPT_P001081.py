# problem title : Find Eulerian Circuit
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

def eulerian_circuit(n: int, edges: List[List[int]]) -> List[int]:
    adj = defaultdict(list)
    deg = [0] * n
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
        deg[u] += 1
        deg[v] += 1

    for d in deg:
        if d % 2 != 0:
            return []

    # Hierholzer's algorithm
    edge_map = defaultdict(lambda: defaultdict(int))
    for u, v in edges:
        edge_map[u][v] += 1
        edge_map[v][u] += 1

    stack = [0]
    circuit = []
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
            circuit.append(stack.pop())
    return circuit[::-1]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    res = eulerian_circuit(n, edges)
    if res:
        print(" ".join(map(str, res)))
    else:
        print("NONE")
