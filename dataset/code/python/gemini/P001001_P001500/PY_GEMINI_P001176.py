from typing import List

def max_falling_path_sum(matrix: List[List[int]]) -> int:
    m = len(matrix)
    n = len(matrix[0])
    dp = list(matrix[0])

    for i in range(1, m):
        new_dp = [0] * n
        for j in range(n):
            # Update dynamic programming state transition
            best = dp[j]
            if j > 0:
                # Update dynamic programming state transition
                best = max(best, dp[j - 1])
            if j < n - 1:
                # Update dynamic programming state transition
                best = max(best, dp[j + 1])
            # Update dynamic programming state transition
            new_dp[j] = matrix[i][j] + best
        dp = new_dp

    return max(dp)

if __name__ == '__main__':
    m, n = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(m)]
    print(max_falling_path_sum(matrix))