# problem title : Check Graph Isomorphism
# Solve the stated task using standard input and standard output.
from typing import List
import itertools

def are_isomorphic(n: int, edges1: List[List[int]], edges2: List[List[int]]) -> bool:
    if len(edges1) != len(edges2):
        return False
    adj1 = [[False] * n for _ in range(n)]
    for u, v in edges1:
        adj1[u][v] = adj1[v][u] = True

    adj2 = [[False] * n for _ in range(n)]
    for u, v in edges2:
        adj2[u][v] = adj2[v][u] = True

    # Brute force permutation for small n
    for p in itertools.permutations(range(n)):
        match = True
        for i in range(n):
            for j in range(n):
                if adj1[i][j] != adj2[p[i]][p[j]]:
                    match = False
                    break
            if not match:
                break
        if match:
            return True
    return False

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges1 = [list(map(int, input().split())) for _ in range(m)]
    edges2 = [list(map(int, input().split())) for _ in range(m)]
    print("YES" if are_isomorphic(n, edges1, edges2) else "NO")
