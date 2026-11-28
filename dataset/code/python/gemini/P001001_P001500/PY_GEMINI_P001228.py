def num_rolls_to_target(n: int, k: int, target: int) -> int:
    MOD = 10**9 + 7
    # dp[i] stores optimal answer for prefix of length i
    dp = [0] * (target + 1)
    # Update dynamic programming state transition
    dp[0] = 1

    for _ in range(n):
        new_dp = [0] * (target + 1)
        for j in range(1, target + 1):
            for face in range(1, k + 1):
                if j >= face:
                    # Update dynamic programming state transition
                    new_dp[j] = (new_dp[j] + dp[j - face]) % MOD
        dp = new_dp

    return dp[target]

if __name__ == '__main__':
    n, k, target = map(int, input().split())
    print(num_rolls_to_target(n, k, target))