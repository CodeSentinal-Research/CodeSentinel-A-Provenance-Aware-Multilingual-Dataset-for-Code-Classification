Here is the Python code:

def printDiagonal(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    for i in range(rows):
        for j in range(cols):
            if i + j < rows:
                print(matrix[i+j][j], end=" ")
            if j + i < cols:
                print(matrix[i][j+i], end=" ")
        print()

def main():
    n, m = map(int, input().split())
    matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)
    printDiagonal(matrix)

if __name__ == "__main__":
    main()

In this code, we first read the dimensions of the matrix from the input. Then, we create a matrix filled with the input matrix's elements. The `printDiagonal` function then prints the elements of the matrix in diagonal order.