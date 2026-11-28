import sys

def solve():
    s = sys.stdin.readline().strip()
    swaps = 0
    black_count = 0
    
    for char in s:
        if char == '1':
            black_count += 1
        else:
            swaps += black_count
            
    print(swaps)

solve()

