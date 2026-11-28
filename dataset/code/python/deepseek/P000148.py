Here is the Python code for your problem:

def is_symmetric(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if matrix[i][j] != matrix[j][i]:
                return False
    return True

def main():
    N = int(input())
    matrix = []
    for _ in range(N):
        row = list(map(int, input().split()))
        matrix.append(row)
    if is_symmetric(matrix):
        print("Symmetric")
    else:
        print("Not Symmetric")

if __name__ == "__main__":
    main()

In this code, `is_symmetric` function is used to check whether a given matrix is symmetric or not. It iterates through each element in the matrix and compares it with the corresponding element from the other side of the matrix. If any pair of elements does not match, it returns False. If no such pair is found, it means the matrix is symmetric and returns True.

In the main function, it gets the input for N (number of rows in the matrix) and for each row, it gets the input as a list of integers. It then calls the `is_symmetric` function and prints "Symmetric" or "Not Symmetric" based on the result.