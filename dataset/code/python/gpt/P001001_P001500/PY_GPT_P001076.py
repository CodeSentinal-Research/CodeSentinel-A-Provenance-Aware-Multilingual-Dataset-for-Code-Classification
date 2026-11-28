# problem title : Floyd-Warshall All-Pairs Shortest Path
# Solve the stated task using standard input and standard output.
from typing import List

def floyd_warshall(n: int, edges: List[List[int]]) -> List[List[int]]:
    dist = [[float('inf')] * n for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0
    for u, v, w in edges:
        dist[u][v] = min(dist[u][v], w)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]

    return [[int(dist[i][j]) if dist[i][j] != float('inf') else -1 for j in range(n)] for i in range(n)]

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    matrix = floyd_warshall(n, edges)
    for row in matrix:
        print(" ".join(map(str, row)))
