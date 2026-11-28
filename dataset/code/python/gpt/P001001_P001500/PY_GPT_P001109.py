# problem title : Graph Coloring Verification
# Solve the stated task using standard input and standard output.
from typing import List

def verify_coloring(n: int, edges: List[List[int]], colors: List[int]) -> bool:
    for u, v in edges:
        if colors[u] == colors[v]:
            return False
    return True

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    colors = list(map(int, input().split()))
    print("VALID" if verify_coloring(n, edges, colors) else "INVALID")
