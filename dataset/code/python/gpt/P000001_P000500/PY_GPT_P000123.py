# problem title : Best Time to Buy and Sell Stock
# Keep the cheapest purchase seen so far and its best later profit.
n = int(input()); prices = list(map(int, input().split()))[:n]
lowest = prices[0]; profit = 0
for price in prices[1:]:
    profit = max(profit, price - lowest)
    lowest = min(lowest, price)
print(profit)
