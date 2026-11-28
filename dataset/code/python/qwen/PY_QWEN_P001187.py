import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    prices = list(map(int, input_data[1:1+n]))
    
    profit = 0
    for i in range(1, n):
        if prices[i] > prices[i-1]:
            profit += prices[i] - prices[i-1]
            
    print(profit)

if __name__ == "__main__":
    solve()

