Here is the Python code for the problem:

def countSubmatrices(matrix):
    rows, cols = len(matrix), len(matrix[0])
    sum_matrix = [[0] * (cols + 1) for _ in range(rows)]
    sum_2d_matrix = [[0] * (cols + 1) for _ in range(rows + 1)]

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                sum_matrix[i][j+1] = 0
            else:
                sum_matrix[i][j+1] = sum_matrix[i][j] + 1

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                sum_2d_matrix[i+1][j] = 0
            else:
                sum_2d_matrix[i+1][j] = sum_2d_matrix[i][j] + 1

    count = 0
    for i in range(rows):
        for j in range(cols):
            for k in range(i + 1, rows + 1):
                for l in range(j + 1, cols + 1):
                    if sum_2d_matrix[i][j] == sum_2d_matrix[k][l] and sum_matrix[i][j] == sum_matrix[k][l]:
                        count += 1

    return count

def main():
    N, M = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(N)]
    print(countSubmatrices(matrix))

if __name__ == "__main__":
    main()

This code first calculates the prefix sums of the 2D and 1D submatrices for each cell in the matrix. Then for each cell, it iterates through the other cells to find the maximum size of the submatrix with the same number of 0s and 1s. The time complexity of this code is O(N^2*M^2), which is quite efficient for large inputs.