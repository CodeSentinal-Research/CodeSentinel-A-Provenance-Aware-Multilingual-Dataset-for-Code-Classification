# problem title : Count Vertices with Zero Out-Degree
# Solve the stated task using standard input and standard output.
from typing import List

def count_zero_out_degree(n: int, edges: List[List[int]]) -> int:
    out_degree = [0] * n
    for u, v in edges:
        out_degree[u] += 1
    return sum(1 for d in out_degree if d == 0)

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print(count_zero_out_degree(n, edges))
