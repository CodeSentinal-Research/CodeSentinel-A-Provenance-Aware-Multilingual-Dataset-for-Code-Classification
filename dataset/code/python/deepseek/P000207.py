Here is the Python code for your problem:

def find_max_hourglass_sum(matrix):
    max_sum = float('-inf')
    for i in range(1, 4):
        for j in range(1, 4):
            sum_hourglass = matrix[i][j] + matrix[i][j+1] + matrix[i][j+2] + matrix[i-1][j+1] + matrix[i-2][j] + matrix[i-2][j+2]
            max_sum = max(sum_hourglass, max_sum)
    return max_sum

if __name__ == "__main__":
    rows, cols = map(int, input().split())
    matrix = [[int(j) for j in input().split()] for i in range(rows)]
    print(find_max_hourglass_sum(matrix))

This code first reads the number of rows and columns, and then the matrix itself. It then calls the `find_max_hourglass_sum` function on the matrix, which calculates the sum of each hourglass and keeps track of the maximum sum. The maximum sum is then printed.