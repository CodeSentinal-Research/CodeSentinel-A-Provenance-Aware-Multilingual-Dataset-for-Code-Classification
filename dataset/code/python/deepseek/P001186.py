Here is the Python code:

def maxProfit(prices):
    if len(prices) < 2:
        return 0

    buy = prices[0]
    profit = 0

    for i in range(1, len(prices)):
        if prices[i] < buy:
            buy = prices[i]
        elif prices[i] - buy > profit:
            profit = prices[i] - buy

    return profit

def main():
    N = int(input().strip())
    prices = list(map(int, input().strip().split()))
    print(maxProfit(prices))

if __name__ == "__main__":
    main()

The `maxProfit` function calculates the maximum profit by buying a stock and selling it at a later time. It iterates over the prices, and whenever it finds a price that is less than the current buy price, it updates the buy price. If the current price - buy price is greater than the current profit, it updates the profit.

The `main` function reads the number of days and the prices, calls `maxProfit`, and prints the result.