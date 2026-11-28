Here's the Python code:

def maxOnesRow(matrix):
    max_ones = 0
    max_row = -1
    for i in range(len(matrix)):
        ones = matrix[i].count(1)
        if ones > max_ones:
            max_ones = ones
            max_row = i
    return max_row

rows = int(input())
matrix = []
for _ in range(rows):
    matrix.append(list(map(int, input().split())))

print(maxOnesRow(matrix))

In this code, we define a function `maxOnesRow` that takes a 2D list (matrix) as input. We initialize `max_ones` to 0 and `max_row` to -1. We then iterate over each row in the matrix, count the number of 1s in it, and if the count is greater than `max_ones`, we update `max_ones` and `max_row`. Finally, we return `max_row`.

The input handling part is done inside a loop that runs `rows` times. In each iteration, we read a row of integers from the standard input, split them into a list of integers, and convert them to an integer.

The result is printed to the standard output.