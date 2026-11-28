Here is the Python code for the problem:

def rotateMatrix(A):
    N = len(A)

    for i in range(N):
        for j in range(i, N):
            A[j][i], A[i][j] = A[i][j], A[j][i]

    for i in range(N):
        A[i] = A[i][::-1]

    return A

def inputMatrix():
    N = int(input("Enter the size of matrix: "))
    A = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            A[i][j] = int(input("Enter the element at A[{}][{}]: ".format(i, j)))
    return A

def printMatrix(A):
    for row in A:
        print(' '.join(str(cell) for cell in row))

def main():
    A = inputMatrix()
    print("Original Matrix:")
    printMatrix(A)

    A = rotateMatrix(A)
    print("Rotated Matrix:")
    printMatrix(A)

if __name__ == "__main__":
    main()
This code first prompts the user for the size of the matrix and then for each element in the matrix. It then rotates the matrix 90 degrees clockwise and prints the resulting matrix.