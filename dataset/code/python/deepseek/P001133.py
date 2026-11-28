Here is the Python code for the problem:

def min_cost_climbing_stairs(cost):
    dp = [0] * len(cost)
    dp[0] = cost[0]
    dp[1] = cost[1]

    for i in range(2, len(cost)):
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]

    return min(dp[-1], dp[-2])


def main():
    N = int(input().strip())
    cost = [int(x) for x in input().strip().split()]
    print(min_cost_climbing_stairs(cost))


if __name__ == "__main__":
    main()

This code uses dynamic programming to solve the problem. The dp array stores the minimum cost to reach the current stair from either the previous stair or the two stairs before. The dp[0] and dp[1] are initialized with the costs of the first and second stairs respectively. For each stair from the 2nd to the last, we compute the minimum cost of reaching that stair by taking the minimum cost from either the previous stair (dp[i-1]) or two stairs before (dp[i-2]).

The main function handles the input and prints the minimum total cost.