from typing import List

def lca_queries(n: int, parent: List[int], queries: List[List[int]]) -> List[int]:
    depth = [0] * n
    for i in range(1, n):
        d = 0
        curr = i
        while curr != 0 and curr != -1:
            curr = parent[curr]
            d += 1
        depth[i] = d

    res = []
    for u, v in queries:
        while depth[u] > depth[v]:
            u = parent[u]
        while depth[v] > depth[u]:
            v = parent[v]
        while u != v:
            u = parent[u]
            v = parent[v]
        res.append(u)
    return res

if __name__ == '__main__':
    n, q = map(int, input().split())
    parent = list(map(int, input().split()))  # parent of 1..n-1 with root 0
    full_parent = [0] + parent
    queries = [list(map(int, input().split())) for _ in range(q)]
    ans = lca_queries(n, full_parent, queries)
    for a in ans:
        print(a)