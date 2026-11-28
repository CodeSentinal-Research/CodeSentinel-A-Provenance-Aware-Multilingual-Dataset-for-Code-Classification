Here is a Python solution for the given problem:

def print_sorted_matrix(matrix):
    N = len(matrix)
    for row in matrix:
        sorted_row = sorted(row)
        print(sorted_row)

    for i in range(N):
        column = [row[i] for row in matrix]
        sorted_column = sorted(column)
        print(sorted_column)


def main():
    N = int(input().strip())
    matrix = []
    for _ in range(N):
        row = list(map(int, input().strip().split()))
        matrix.append(row)
    print_sorted_matrix(matrix)


if __name__ == "__main__":
    main()

This program first reads the number N of elements in the matrix. It then reads the matrix in a 2D list format. It then calls the `print_sorted_matrix` function, which prints the elements in sorted order. The `main` function handles the input and output.