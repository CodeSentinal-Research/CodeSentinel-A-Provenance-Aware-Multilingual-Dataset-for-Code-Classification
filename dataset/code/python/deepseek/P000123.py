Here is the Python code for the problem:

def maxProfit(prices):
    maxProfit = 0
    minPrice = prices[0]

    for price in prices:
        minPrice = min(minPrice, price)
        profit = price - minPrice
        maxProfit = max(maxProfit, profit)

    return maxProfit

def main():
    n = int(input())
    prices = list(map(int, input().split()))
    print(maxProfit(prices))

if __name__ == "__main__":
    main()

In this code, we use a simple approach where we keep track of the minimum price and the maximum profit we can get for each day. We iterate over the list of prices and for each day, we calculate the profit if we sell the stock on that day and buy the stock on the previous day (since we can only sell on a day after buying) and update our maximum profit if this profit is more than our current maximum profit.

The main function reads the number of days and the prices, calls the maxProfit function and prints the result.