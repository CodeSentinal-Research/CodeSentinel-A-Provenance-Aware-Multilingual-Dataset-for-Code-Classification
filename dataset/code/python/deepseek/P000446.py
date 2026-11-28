def search_in_sorted_matrix(rows, cols, target, matrix):
    row = 0
    col = cols - 1

    while row < rows and col >= 0:
        if matrix[row][col] == target:
            return "Found"
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1
    return "Not Found"


def main():
    [rows, cols, target] = map(int, input().split())
    matrix = [[int(cell) for cell in row.split()] for row in range(rows)]
    print(search_in_sorted_matrix(rows, cols, target, matrix))


if __name__ == "__main__":
    main()

This Python code defines a function `search_in_sorted_matrix` that takes the number of rows, columns, target, and a matrix as inputs, and returns a string indicating whether the target is found in the matrix.

The `main` function reads the number of rows, columns, and the target from the input, creates the matrix, and then calls `search_in_sorted_matrix` with these inputs.

The `if __name__ == "__main__":` line ensures that the `main` function is only run if this file is the entry point for the program.