Sure, here is the Python code for the problem:

import numpy as np

def is_orthogonal(matrix):
    transpose = matrix.T
    product = np.dot(matrix, transpose)
    return np.allclose(product, np.eye(len(matrix)))

def main():
    N = int(input())
    matrices = [np.array([list(map(int, input().split())) for _ in range(N)] for _ in range(N)]
    for matrix in matrices:
        print('Yes' if is_orthogonal(matrix) else 'No')

if __name__ == "__main__":
    main()

In this code, we first import the necessary libraries. Then, we define a function `is_orthogonal` that checks if a matrix is orthogonal. It does this by computing the product of the matrix and its transpose, and then checking if this is close to the identity matrix. We use `numpy.allclose` to check for equality within a tolerance.

The `main` function reads the number of matrices and the matrices themselves. It then checks each matrix for orthogonality and prints the result.