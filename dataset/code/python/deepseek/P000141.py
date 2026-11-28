Sure, here is a Python code for rotating a matrix 90 degrees clockwise:

def rotate_matrix(matrix):
    N = len(matrix)
    for i in range(N):
        for j in range(i, N):
            matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
    for i in range(N):
        matrix[i] = matrix[i][::-1]
    return matrix

def input_matrix():
    N = int(input().strip())
    matrix = []
    for i in range(N):
        row = list(map(int, input().strip().split()))
        matrix.append(row)
    return matrix

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))

def main():
    matrix = input_matrix()
    matrix = rotate_matrix(matrix)
    print_matrix(matrix)

if __name__ == '__main__':
    main()
This code first reads the size of the matrix, and then the matrix itself. The transpose of the matrix is obtained by swapping the elements of the matrix. The reversal of each row is done, which rotates the matrix 90 degrees clockwise.