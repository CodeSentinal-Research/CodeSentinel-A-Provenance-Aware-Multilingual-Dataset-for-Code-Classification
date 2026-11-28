Here is the Python code for the problem:

def stone_game(n, piles):
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + piles[i]

    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

    sum_ = sum(piles)
    for i in range(n):
        if dp[i][n - 1] > sum_ - dp[i][n - 1]:
            return 'YES'
    return 'NO'

def main():
    n = int(input().strip())
    piles = list(map(int, input().strip().split()))
    print(stone_game(n, piles))

if __name__ == "__main__":
    main()

This code first calculates the prefix sum of the pile sizes to get the maximum stones that can be removed by the first player in each pile. Then it uses dynamic programming to find the optimal strategy for the first player. It iterates over the length of the piles and for each length, it calculates the maximum stones that can be removed by the first player. Finally, it returns 'YES' if the first player can win by the maximum stones that can be removed in the optimal strategy, otherwise it returns 'NO'.