Here is the Python code for finding the maximum sum path in a matrix:

def find_max_sum(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    dp = [[0]*cols for _ in range(rows)]

    dp[0][0] = matrix[0][0]

    for i in range(1, rows):
        dp[i][0] = dp[i-1][0] + matrix[i][0]

    for j in range(1, cols):
        dp[0][j] = dp[0][j-1] + matrix[0][j]

    for i in range(1, rows):
        for j in range(1, cols):
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + matrix[i][j]

    return dp[-1][-1]

def main():
    n = int(input().strip())

    matrix = []
    for i in range(n):
        row = list(map(int, input().strip().split()))
        matrix.append(row)

    print(find_max_sum(matrix))

if __name__ == "__main__":
    main()

In this code, we first read the number of rows and columns, and then the matrix itself. We then call the `find_max_sum` function which calculates the maximum sum path and prints it.