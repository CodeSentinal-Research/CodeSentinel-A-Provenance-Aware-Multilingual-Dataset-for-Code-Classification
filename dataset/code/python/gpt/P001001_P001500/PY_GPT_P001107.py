# problem title : Transitive Closure of a Directed Graph
# Solve the stated task using standard input and standard output.
from typing import List

def transitive_closure(n: int, edges: List[List[int]]) -> List[List[int]]:
    reach = [[0] * n for _ in range(n)]
    for i in range(n):
        reach[i][i] = 1
    for u, v in edges:
        reach[u][v] = 1

    for k in range(n):
        for i in range(n):
            for j in range(n):
                reach[i][j] = reach[i][j] or (reach[i][k] and reach[k][j])

    return reach

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    matrix = transitive_closure(n, edges)
    for row in matrix:
        print(" ".join(map(str, row)))
