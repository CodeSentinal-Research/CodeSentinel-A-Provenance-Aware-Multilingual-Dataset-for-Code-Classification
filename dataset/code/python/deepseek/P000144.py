Here is the Python code for the problem:

def set_matrix_zeroes(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    rows_zero = cols_zero = -1

    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                if rows_zero == -1:
                    rows_zero = i
                cols_zero = j

    if rows_zero != -1 or cols_zero != -1:
        for i in range(rows):
            for j in range(cols):
                if i == rows_zero or j == cols_zero:
                    matrix[i][j] = 0

        for i in range(rows):
            if rows_zero != -1:
                for j in range(cols):
                    matrix[i][j] = 0

        for i in range(cols):
            if cols_zero != -1:
                for j in range(rows):
                    matrix[j][i] = 0

    return matrix


def main():
    n, m = map(int, input().split())
    matrix = [[int(j) for j in input().split()] for i in range(n)]
    print("\n".join(map(str, set_matrix_zeroes(matrix))))


if __name__ == "__main__":
    main()

In this code, we first read the size of the matrix (n, m) from the first line. Then we read the matrix from the second line onwards. The `set_matrix_zeroes` function is responsible for setting the entire row and column to zero if an element is zero. The `main` function calls the `set_matrix_zeroes` function and then prints the modified matrix.