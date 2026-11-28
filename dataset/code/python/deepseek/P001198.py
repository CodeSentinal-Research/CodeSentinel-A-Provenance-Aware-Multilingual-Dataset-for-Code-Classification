def count_squares(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    dp = [[0]*cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 1:
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    return sum(sum(row) for row in dp)

if __name__ == "__main__":
    rows, cols = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(rows)]
    print(count_squares(matrix))