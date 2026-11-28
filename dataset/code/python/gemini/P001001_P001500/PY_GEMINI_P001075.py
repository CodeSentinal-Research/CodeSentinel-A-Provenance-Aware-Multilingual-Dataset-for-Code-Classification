from typing import List

def bellman_ford(n: int, edges: List[List[int]], src: int):
    dist = [float('inf')] * n
    dist[src] = 0
    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # check negative cycle
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return None  # Negative cycle

    return [int(d) if d != float('inf') else -1 for d in dist]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    src = int(input())
    res = bellman_ford(n, edges, src)
    if res is None:
        print("NEGATIVE CYCLE")
    else:
        print(" ".join(map(str, res)))