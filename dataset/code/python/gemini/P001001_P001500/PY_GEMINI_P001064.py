from typing import List

def edge_exists(n: int, edges: List[List[int]], u: int, v: int) -> bool:
    edge_set = set((min(x, y), max(x, y)) for x, y in edges)
    return (min(u, v), max(u, v)) in edge_set

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    u, v = map(int, input().split())
    print("YES" if edge_exists(n, edges, u, v) else "NO")