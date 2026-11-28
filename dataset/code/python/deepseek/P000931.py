Here's the code:

def matrix_transpose(N, M, A):
    transpose = [[0 for _ in range(N)] for _ in range(M)]

    for i in range(N):
        for j in range(M):
            transpose[j][i] = A[i][j]

    return transpose

N = int(input("Enter the number of rows (N): "))
M = int(input("Enter the number of columns (M): "))

A = []
for _ in range(N):
    row = list(map(int, input("Enter a row (separated by space): ").split()))
    A.append(row)

result = matrix_transpose(N, M, A)
for row in result:
    print(row)

In this code, we first create a function `matrix_transpose` that takes as input the dimensions of the matrix (N and M) and the matrix itself. We then create a new matrix of the same size filled with zeros and fill it in a way that each element at the position `(i, j)` of the new matrix is the element at the same position in the input matrix.

Then, we read the dimensions of the matrix and the elements of the matrix from the standard input. We call the function with these inputs and print the result.