from typing import List

def mst_weight(n: int, edges: List[List[int]]) -> int:
    parent = list(range(n))
    def find(i):
        if parent[i] == i: return i
        parent[i] = find(parent[i])
        return parent[i]

    edges.sort(key=lambda e: e[2])
    total_weight = 0
    count = 0
    for u, v, w in edges:
        ru, rv = find(u), find(v)
        if ru != rv:
            parent[ru] = rv
            total_weight += w
            count += 1
            if count == n - 1:
                break
    return total_weight

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print(mst_weight(n, edges))