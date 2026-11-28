Here is the Python code for the given problem:

def diagonal_sum(n, matrix):
    primary_diagonal_sum = 0
    secondary_diagonal_sum = 0

    for i in range(n):
        primary_diagonal_sum += matrix[i][i]
        secondary_diagonal_sum += matrix[i][n-i-1]

    return primary_diagonal_sum, secondary_diagonal_sum

def main():
    n = int(input("Enter the size of the matrix: "))
    matrix = [[int(input(f"Enter element at [{i}][{j}]: ")) for j in range(n)] for i in range(n)]
    primary_diagonal_sum, secondary_diagonal_sum = diagonal_sum(n, matrix)
    print(f"The sum of the primary diagonal is: {primary_diagonal_sum}")
    print(f"The sum of the secondary diagonal is: {secondary_diagonal_sum}")

if __name__ == "__main__":
    main()

In this code, we first define a function `diagonal_sum` which takes the size of the matrix and the matrix itself as inputs and returns the sum of the main diagonal and the secondary diagonal. We then define a main function which handles the input and outputs the results of the `diagonal_sum` function.