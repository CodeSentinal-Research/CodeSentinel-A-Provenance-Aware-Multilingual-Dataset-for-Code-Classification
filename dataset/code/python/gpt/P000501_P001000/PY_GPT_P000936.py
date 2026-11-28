# problem title : Check Symmetric Matrix
# Solve the stated task using standard input and standard output.
from typing import List

def is_symmetric(mat: List[List[int]]) -> bool:
    n = len(mat)
    for i in range(n):
        for j in range(i + 1, n):
            if mat[i][j] != mat[j][i]:
                return False
    return True

if __name__ == '__main__':
    n = int(input())
    mat = [list(map(int, input().split())) for _ in range(n)]
    print("YES" if is_symmetric(mat) else "NO")
