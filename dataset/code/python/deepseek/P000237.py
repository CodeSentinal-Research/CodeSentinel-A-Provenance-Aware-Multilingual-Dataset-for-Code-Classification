Here is the Python code:

def rotate_matrix(matrix, k):
    k %= len(matrix)
    if k == 0:
        return matrix

    def rotate(m):
        n = len(m)
        for i in range(n // 2):
            for j in range(i, n - i - 1):
                m[i][j], m[j][n - i - 1], m[n - i - 1][n - j - 1], m[n - j - 1][i] = m[n - j - 1][i], m[i][j], m[j][n - i - 1], m[n - i - 1][n - j - 1]

    for _ in range(k):
        rotate(matrix)

    return matrix

def main():
    rows, cols, k = map(int, input().split())
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, input().split())))
    print(rotate_matrix(matrix, k))

if __name__ == "__main__":
    main()

This code first reads the number of rows, columns, and the number of rotations from the input. It then reads the matrix. The rotate_matrix function rotates the matrix by one step to the right. This is done by swapping each element with its corresponding element in the other direction. The rotate function performs the rotation. The main function calls the rotate_matrix function and prints the result.