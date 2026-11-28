def maxProfit(prices):
    N = len(prices)
    if N == 0:
        return 0

    left, right = [0]*N, [0]*N
    min_price = prices[0]
    max_profit = 0

    for i in range(1, N):
        min_price = min(min_price, prices[i])
        max_profit = max(max_profit, prices[i] - min_price)
        left[i] = max_profit

    max_price = prices[N-1]
    max_profit = 0

    for i in range(N-2, -1, -1):
        max_price = max(max_price, prices[i])
        max_profit = max(max_profit, max_price - prices[i])
        right[i] = max_profit

    result = 0

    for i in range(N):
        result = max(result, left[i] + right[i])

    return result


def main():
    N = int(input().strip())
    prices = list(map(int, input().strip().split()))
    print(maxProfit(prices))


if __name__ == '__main__':
    main()