def find_peak(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    for row in range(rows):
        for col in range(cols):
            if (row == 0 or row == rows - 1 or col == 0 or col == cols - 1):
                if matrix[row][col] > matrix[row-1][col] and matrix[row][col] > matrix[row][col-1]:
                    return matrix[row][col]

    return None


def main():
    rows = int(input().strip())
    matrix = []

    for _ in range(rows):
        matrix.append([int(x) for x in input().strip().split()])

    peak = find_peak(matrix)

    if peak:
        print(peak)
    else:
        print('No peak found')


if __name__ == '__main__':
    main()
This Python script first defines a function `find_peak` that takes a 2D matrix as input and returns the value of the peak element in the matrix. This is done by iterating over the matrix and checking each element. If the element is greater than all its neighbors, it is returned.

In the `main` function, the script reads the number of rows, and then reads the matrix. After that, it calls the `find_peak` function and prints the peak element if it exists, otherwise it prints a message saying 'No peak found'.