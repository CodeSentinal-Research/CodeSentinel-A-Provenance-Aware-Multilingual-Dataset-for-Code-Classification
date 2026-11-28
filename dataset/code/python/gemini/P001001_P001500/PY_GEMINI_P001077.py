from typing import List

def kruskal_mst(n: int, edges: List[List[int]]) -> List[List[int]]:
    parent = list(range(n))
    def find(i):
        if parent[i] == i: return i
        parent[i] = find(parent[i])
        return parent[i]

    edges.sort(key=lambda e: (e[2], min(e[0], e[1]), max(e[0], e[1])))
    mst = []
    for u, v, w in edges:
        ru, rv = find(u), find(v)
        if ru != rv:
            parent[ru] = rv
            mst.append([min(u, v), max(u, v), w])
            if len(mst) == n - 1:
                break
    return mst

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    res = kruskal_mst(n, edges)
    for u, v, w in res:
        print(f"{u} {v} {w}")