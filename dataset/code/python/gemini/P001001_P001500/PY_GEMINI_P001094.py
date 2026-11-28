from typing import List

def max_bipartite_matching(m: int, n: int, adj_matrix: List[List[int]]) -> int:
    match_r = [-1] * n

    def bpm(u: int, seen: List[bool]) -> bool:
        for v in range(n):
            if adj_matrix[u][v] and not seen[v]:
                seen[v] = True
                if match_r[v] < 0 or bpm(match_r[v], seen):
                    match_r[v] = u
                    return True
        return False

    result = 0
    for u in range(m):
        seen = [False] * n
        if bpm(u, seen):
            result += 1
    return result

if __name__ == '__main__':
    m, n, k = map(int, input().split())
    adj = [[0] * n for _ in range(m)]
    for _ in range(k):
        u, v = map(int, input().split())
        adj[u][v] = 1
    print(max_bipartite_matching(m, n, adj))