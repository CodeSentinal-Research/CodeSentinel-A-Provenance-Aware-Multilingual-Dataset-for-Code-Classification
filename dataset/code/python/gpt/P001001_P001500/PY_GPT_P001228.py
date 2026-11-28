# problem title : Dice Throw Problem
# Solve the stated task using standard input and standard output.
def num_rolls_to_target(n: int, k: int, target: int) -> int:
    MOD = 10**9 + 7
    dp = [0] * (target + 1)
    dp[0] = 1

    for _ in range(n):
        new_dp = [0] * (target + 1)
        for j in range(1, target + 1):
            for face in range(1, k + 1):
                if j >= face:
                    new_dp[j] = (new_dp[j] + dp[j - face]) % MOD
        dp = new_dp

    return dp[target]

if __name__ == '__main__':
    n, k, target = map(int, input().split())
    print(num_rolls_to_target(n, k, target))
