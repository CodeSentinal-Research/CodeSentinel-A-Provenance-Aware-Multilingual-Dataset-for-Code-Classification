import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    prices = list(map(int, input_data[1:1+n]))
    
    if n == 0:
        print(0)
        return
        
    hold = -prices[0]
    sold = 0
    rest = 0
    
    for i in range(1, n):
        prev_hold = hold
        hold = max(hold, rest - prices[i])
        rest = max(rest, sold)
        sold = prev_hold + prices[i]
        
    print(max(sold, rest))

if __name__ == "__main__":
    solve()

