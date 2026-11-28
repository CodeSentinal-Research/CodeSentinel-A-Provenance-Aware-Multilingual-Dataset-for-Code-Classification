Here is the Python code for the problem:

def modify_matrix(matrix):
    row_count = len(matrix)
    col_count = len(matrix[0])

    for i in range(row_count):
        for j in range(col_count):
            if matrix[i][j] == 1:
                for k in range(col_count):
                    matrix[i][k] = 1
                for l in range(row_count):
                    matrix[l][j] = 1

    return matrix

def main():
    row_col = input().split()
    row_count = int(row_col[0])
    col_count = int(row_col[1])

    matrix = []
    for i in range(row_count):
        row = list(map(int, input().split()))
        matrix.append(row)

    modified_matrix = modify_matrix(matrix)
    for row in modified_matrix:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()

In this code, the `modify_matrix` function takes a boolean matrix as input. It then iterates over each cell in the matrix. If a cell is 1, it sets all cells in the row and the column to 1.

The `main` function reads the number of rows and columns from the input, and then reads the matrix from the standard input. It then calls the `modify_matrix` function and prints the modified matrix to the standard output.