import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    prices = list(map(int, input_data[1:1+n]))
    
    if n < 2:
        print(0)
        return
        
    min_price = prices[0]
    max_profit = 0
    
    for price in prices[1:]:
        max_profit = max(max_profit, price - min_price)
        min_price = min(min_price, price)
        
    print(max_profit)

if __name__ == "__main__":
    solve()

