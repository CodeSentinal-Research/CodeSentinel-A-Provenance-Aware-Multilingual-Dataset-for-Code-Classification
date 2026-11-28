Here is the python code for the given problem:

def max_square(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    sizes = [[0 for _ in range(cols + 1)] for _ in range(rows + 1)]

    max_size = 0

    for i in range(1, rows + 1):
        for j in range(1, cols + 1):
            if matrix[i - 1][j - 1] == 1:
                sizes[i][j] = min(min(sizes[i][j - 1], sizes[i - 1][j]), sizes[i - 1][j - 1]) + 1
                max_size = max(max_size, sizes[i][j])

    return max_size * max_size


def main():
    R, C = map(int, input().split())
    matrix = [[int(x) for x in input().split()] for _ in range(R)]
    print(max_square(matrix))


if __name__ == "__main__":
    main()

In this code, we first initialize a 2D array (`sizes`) to store the sizes of the largest square. We then iterate over the matrix and populate the `sizes` array. In the `sizes` array, `sizes[i][j]` will be the size of the largest square that can be formed with a 1 at the cell `(i, j)`.

Finally, we return the maximum size of the square (`max_size`) and return its square.

The main function reads the number of rows and columns from the input, reads the matrix from the input, and then calls the `max_square` function.