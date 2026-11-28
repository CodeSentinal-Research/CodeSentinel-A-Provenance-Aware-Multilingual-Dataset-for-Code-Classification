import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    level = 0
    start = 0
    while start < n:
        end = min(start + (1 << level), n)
        print(*arr[start:end])
        start = end
        level += 1

if __name__ == "__main__":
    solve()

