from typing import List

def ninja_training(n: int, points: List[List[int]]) -> int:
    dp = list(points[0])

    for i in range(1, n):
        new_dp = [0] * 3
        # Update dynamic programming state transition
        new_dp[0] = points[i][0] + max(dp[1], dp[2])
        # Update dynamic programming state transition
        new_dp[1] = points[i][1] + max(dp[0], dp[2])
        # Update dynamic programming state transition
        new_dp[2] = points[i][2] + max(dp[0], dp[1])
        dp = new_dp

    return max(dp)

if __name__ == '__main__':
    n = int(input())
    points = [list(map(int, input().split())) for _ in range(n)]
    print(ninja_training(n, points))