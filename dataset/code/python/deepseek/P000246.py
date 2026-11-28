Here's the Python code:

def print_upper_triangular_matrix():
    N = int(input())
    matrix = [list(map(int, input().split())) for _ in range(N)]

    for i in range(N):
        for j in range(i+1):
            print(matrix[i][j], end=" ")
        print()

print_upper_triangular_matrix()

This program reads the dimensions N of the matrix, and then the matrix itself. It then prints the upper triangular part of the matrix.