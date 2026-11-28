# problem title : Probability of Dice Sum
# Solve the stated task using standard input and standard output.
def dice_sum_prob(n: int, target: int) -> float:
    if target < n or target > 6 * n:
        return 0.0
    dp = [0.0] * (6 * n + 1)
    for i in range(1, 7):
        dp[i] = 1.0 / 6.0
    
    for dice in range(2, n + 1):
        next_dp = [0.0] * (6 * n + 1)
        for s in range(dice, 6 * dice + 1):
            for face in range(1, 7):
                if s - face >= dice - 1:
                    next_dp[s] += dp[s - face] / 6.0
        dp = next_dp
    return dp[target]

if __name__ == '__main__':
    n, target = map(int, input().split())
    print(f"{dice_sum_prob(n, target):.6f}")
