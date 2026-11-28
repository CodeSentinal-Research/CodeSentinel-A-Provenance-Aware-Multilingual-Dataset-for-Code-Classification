Here's a Python solution for the given problem using nested list comprehension. This code will take matrix dimensions as inputs and print their product.

def matrix_mult(A, B):
    return [[sum(a*b for a, b in zip(row, col)) for col in zip(*B)] for row in A]

def main():
    N, M, P = map(int, input().split())
    A = [[int(j) for j in input().split()] for i in range(N)]
    B = [[int(j) for j in input().split()] for i in range(M)]

    print("\nProduct of the matrices:")
    for row in matrix_mult(A, B):
        print(" ".join(str(x) for x in row))

if __name__ == "__main__":
    main()

This program takes the matrix dimensions N, M and P as input and then takes the matrices A and B as input. The matrix_mult function takes two matrices and returns their product. The main function calls the matrix_mult function and prints the result.

The input for the matrices A and B should be provided in the following format:

The first line of input should contain N, M and P (the number of rows and columns of the matrices respectively).

After that, N lines of input should follow where each line contains M integers representing the rows of matrix A.

Next, M lines of input should follow where each line contains P integers representing the rows of matrix B.

The program then prints the product of the matrices A and B.