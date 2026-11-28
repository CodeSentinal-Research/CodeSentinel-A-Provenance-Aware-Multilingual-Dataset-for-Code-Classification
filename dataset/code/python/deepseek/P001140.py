def knapsack():
    N = int(input())
    weights = [0]*N
    values = [0]*N

    for i in range(N):
        weights[i], values[i] = map(int, input().split())

    W = int(input())

    dp = [0]*(W+1)

    for i in range(N):
        for j in range(weights[i], W+1):
            dp[j] = max(dp[j], dp[j-weights[i]]+values[i])

    print(dp[W])


if __name__ == "__main__":
    knapsack()

This Python code defines a function `knapsack` that takes input N, weights and values for the items, and the capacity W of the knapsack. It then uses a dynamic programming approach to find the maximum value obtainable in the knapsack. The code first initializes an array `dp` with size `W+1` and sets all elements to 0. It then iterates over each item and for each item, it iterates from `weights[i]` to `W`, updating `dp[j]` to be the maximum of `dp[j]` and `dp[j-weights[i]]+values[i]`. Finally, it prints `dp[W]`, which is the maximum obtainable value.