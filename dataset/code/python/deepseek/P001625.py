Here is the Python code:

def solve():
    N, M = map(int, input().split())
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().split())))

    prefix_sum_matrix = [[0 for _ in range(M+1)] for _ in range(N+1)]

    for i in range(1, N+1):
        for j in range(1, M+1):
            prefix_sum_matrix[i][j] = prefix_sum_matrix[i][j-1] + prefix_sum_matrix[i-1][j] - prefix_sum_matrix[i-1][j-1] + matrix[i-1][j-1]

    for row in prefix_sum_matrix:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    solve()

In the code above, we first read the number of rows and columns N and M from the input. Then we read the matrix data. After that, we create a new 2D list `prefix_sum_matrix` with all elements initialized to zero. We then iterate over the matrix and calculate the prefix sum for each cell, storing it in the prefix_sum_matrix. Finally, we print the prefix_sum_matrix.