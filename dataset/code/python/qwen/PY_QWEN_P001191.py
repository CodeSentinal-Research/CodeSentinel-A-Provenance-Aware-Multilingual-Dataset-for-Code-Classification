import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    fee = int(input_data[idx]); idx += 1
    prices = list(map(int, input_data[idx:idx+n]))
    
    hold = -prices[0]
    cash = 0
    
    for i in range(1, n):
        hold = max(hold, cash - prices[i])
        cash = max(cash, hold + prices[i] - fee)
        
    print(cash)

if __name__ == "__main__":
    solve()

