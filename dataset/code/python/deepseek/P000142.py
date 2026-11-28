Here is the Python code:

def spiralOrder(matrix):
    res = []
    while matrix:
        res += matrix.pop(0)
        if matrix and matrix[0]:
            for row in matrix:
                res.append(row.pop())
        if matrix:
            res += matrix.pop()[::-1]
        if matrix and matrix[0]:
            for row in matrix[::-1]:
                res.append(row.pop(0))
    return res


def main():
    rows, cols = map(int, input().split())
    matrix = [[int(col) for col in input().split()] for _ in range(rows)]
    print(spiralOrder(matrix))


if __name__ == '__main__':
    main()

This code first reads the number of rows and columns. Then it reads the matrix. It prints the spiral order of the matrix.