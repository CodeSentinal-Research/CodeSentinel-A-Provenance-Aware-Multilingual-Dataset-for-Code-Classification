# problem title : Check Identity Matrix
# Solve the stated task using standard input and standard output.
from typing import List

def is_identity_matrix(mat: List[List[int]]) -> bool:
    n = len(mat)
    for i in range(n):
        for j in range(n):
            expected = 1 if i == j else 0
            if mat[i][j] != expected:
                return False
    return True

if __name__ == '__main__':
    n = int(input())
    mat = [list(map(int, input().split())) for _ in range(n)]
    print("YES" if is_identity_matrix(mat) else "NO")
