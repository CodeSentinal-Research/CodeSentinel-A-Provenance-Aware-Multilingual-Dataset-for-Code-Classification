from typing import List

def find_neighbors(n: int, edges: List[List[int]], target: int) -> List[int]:
    neighbors = []
    for u, v in edges:
        if u == target:
            neighbors.append(v)
        elif v == target:
            neighbors.append(u)
    return sorted(neighbors)

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    target = int(input())
    res = find_neighbors(n, edges, target)
    print(" ".join(map(str, res)))