Here is the Python code for the problem:

def maxProfit(k, prices):
    n = len(prices)

    if n < 2:
        return 0

    if n == 2:
        return max(0, prices[1] - prices[0])

    profit = [0] * n
    buy = [-prices[0]] * n
    sell = [0] * n

    for i in range(1, n):
        prev_profit = max(sell[i - 1], buy[i - 1] + prices[i])
        prev_buy = max(buy[i - 1], sell[i - 1] - prices[i])
        prev_sell = max(sell[i - 1], buy[i - 1] - prices[i])

        buy[i] = prev_buy
        sell[i] = prev_sell
        profit[i] = prev_profit

    if k % 2 == 0:
        max_profit = max(sell[n - 1], profit[n - 2] + prices[n - 1])
    else:
        max_profit = sell[n - 1]

    return max_profit

def main():
    n, k = map(int, input().split())
    prices = list(map(int, input().split()))
    print(maxProfit(k, prices))

if __name__ == "__main__":
    main()

In the code above, we use a dynamic programming approach to solve the problem. First, we initialize three lists: `buy`, `sell`, and `profit`. `buy[i]` and `sell[i]` are the maximum profit we can have if we have bought at the `i`-th day and sold at the `i`-th day. `profit[i]` is the maximum profit if we have at most `i` transactions. 

After calculating the `profit` and `buy` and `sell` lists, we update `profit` and `buy` and `sell` lists for the next day and finally for the last day. If `k` is even, we take the maximum profit for the last day and the second last day; otherwise, we take the maximum profit for the last day. 

The main function reads the input, calls `maxProfit`, and prints the result.