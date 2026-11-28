Here is the Python code for the recursive matrix chain multiplication problem.

def matrix_chain_multiplication(dims, i, j):
    if i == j:
        return 0

    min_cost = float('inf')
    for k in range(i, j):
        cost = matrix_chain_multiplication(dims, i, k) + \
               matrix_chain_multiplication(dims, k + 1, j) + \
               dims[i - 1] * dims[k] * dims[j]
        min_cost = min(min_cost, cost)

    return min_cost

def main():
    dims = list(map(int, input().split()))
    print(matrix_chain_multiplication(dims, 1, len(dims) - 1))

if __name__ == "__main__":
    main()
In this code, we define a function `matrix_chain_multiplication` that calculates the minimum cost of multiplying the matrix chain. The function is recursive and uses dynamic programming to store the minimum cost for each subproblem. The base case is when we have only one matrix, which is already solved in one operation.

In the `main` function, we read the dimensions of the matrix chain from the input. The dimensions are given in a line, separated by spaces. We then call the `matrix_chain_multiplication` function with these dimensions, and print the result.

This code assumes that the dimensions of the matrices are integers, and that the length of the input list is at least 2.