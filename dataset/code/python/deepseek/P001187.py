Here is the Python code:

def maxProfit(prices):
    max_profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            max_profit += prices[i] - prices[i - 1]
    return max_profit

def main():
    N = int(input().strip())
    prices = list(map(int, input().strip().split()))
    print(maxProfit(prices))

if __name__ == "__main__":
    main()

The `maxProfit` function calculates the maximum profit that can be obtained by selling the stock after buying it. It does this by iterating through the list of prices, and for each day where the price is greater than the previous day, it adds the difference to the total profit.

The `main` function reads the number of days (N), and the prices of each day, then calls `maxProfit` to calculate and print the maximum profit.