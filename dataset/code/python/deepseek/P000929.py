Here's the Python code for your problem:

def matrix_addition():
    N, M = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(N)]
    B = [list(map(int, input().split())) for _ in range(N)]
    result = [[A[i][j] + B[i][j] for j in range(M)] for i in range(N)]
    for row in result:
        print(*row)

matrix_addition()

This program first reads the number of rows (N) and columns (M) from the input. It then reads the matrices A and B. After that, it adds the corresponding elements from both matrices and prints the resulting matrix.