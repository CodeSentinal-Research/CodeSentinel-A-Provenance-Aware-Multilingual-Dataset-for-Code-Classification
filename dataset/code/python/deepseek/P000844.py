def max_tastiness(n, prices, k):
    prices.sort()
    return max(prices[i+1]-prices[i] for i in range(n-k))

print(max_tastiness(5, [2, 1, 6, 5, 4], 3))