Sure, here is the Python code for your problem:

def rotate(matrix):
    if not matrix or len(matrix) == 0:
        return

    rows = len(matrix)
    cols = len(matrix[0])

    for i in range(rows):
        for j in range(i, cols):
            matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]

    for i in range(rows):
        matrix[i] = matrix[i][::-1]

    return matrix

def read_input():
    row, col = map(int, input().split())
    matrix = [[int(col) for col in input().split()] for _ in range(row)]
    return matrix

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    matrix = read_input()
    rotated_matrix = rotate(matrix)
    print_matrix(rotated_matrix)

This code first reads the number of rows and columns from the input, then reads the matrix elements. After the matrix is read, the `rotate` function is called, which first transposes the matrix (swaps the elements in the upper left corner with the elements in the lower right corner), then reverses each row. Finally, the rotated matrix is printed out.