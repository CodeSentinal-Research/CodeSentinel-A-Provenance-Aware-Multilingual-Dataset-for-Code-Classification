Here is the Python code for the problem:

def find_row_with_max_ones(rows, matrix):
    max_ones = 0
    max_row_index = 0
    for i in range(rows):
        ones = matrix[i].count(1)
        if ones > max_ones:
            max_ones = ones
            max_row_index = i
    return max_row_index

def main():
    rows, cols = map(int, input().split())
    matrix = []
    for _ in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)
    max_row_index = find_row_with_max_ones(rows, matrix)
    print(max_row_index)

if __name__ == "__main__":
    main()

In this code, `find_row_with_max_ones` function finds the row with the maximum number of 1s in a binary matrix. It iterates through each row, counts the number of 1s in the row, and compares it with the current maximum number of 1s. If the current row has more 1s than the current maximum, it updates the maximum and the row index.

In the `main` function, it first reads the number of rows and columns from the input, then it reads the matrix from the input. After that, it calls the `find_row_with_max_ones` function to find the index of the row with the maximum number of 1s, and prints the index.

Please note that the input to the `main` function is a bit different from the example given in the problem. The input is a single line that contains the number of rows and columns, followed by the matrix rows. The matrix rows are read one by one, and each row is a single line containing the matrix elements.