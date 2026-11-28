Here is a Python solution for the problem:

def maxProfit(prices):
    n = len(prices)
    if n < 2:
        return 0

    sold = [0] * n
    hold = [0] * n

    hold[0] = -prices[0]

    for i in range(1, n):
        sold[i] = max(sold[i-1], hold[i-1] + prices[i])
        hold[i] = max(hold[i-1], sold[i-2] - prices[i])

    return max(sold[-1], hold[-1])

if __name__ == "__main__":
    n = int(input().strip())
    prices = list(map(int, input().strip().split()))
    print(maxProfit(prices))

This solution uses a dynamic programming approach to solve the problem. The `sold` and `hold` arrays represent the maximum profit that can be obtained up to the current day. The `hold` array represents the maximum profit we can get if we hold a stock after the previous day, and the `sold` array represents the maximum profit if we sold a stock after the previous day.

In the end, we return the maximum profit of either `sold` or `hold`.

The input handling part is in the `if __name__ == "__main__"` block at the bottom of the code. It reads the number of days (N), and the daily prices (prices). It then calls the `maxProfit` function with these inputs, and prints the result.