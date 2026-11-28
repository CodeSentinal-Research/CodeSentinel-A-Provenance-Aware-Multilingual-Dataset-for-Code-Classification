from typing import List

def matrix_trace(mat: List[List[int]]) -> int:
    return sum(mat[i][i] for i in range(len(mat)))

if __name__ == '__main__':
    n = int(input())
    mat = [list(map(int, input().split())) for _ in range(n)]
    print(matrix_trace(mat))