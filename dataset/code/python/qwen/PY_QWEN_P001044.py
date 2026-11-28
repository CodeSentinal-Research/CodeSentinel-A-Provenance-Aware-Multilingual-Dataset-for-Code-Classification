import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    i = int(input_data[1+n])
    
    # Level of node i is floor(log2(i+1))
    if i == 0:
        print(0)
    else:
        print(int(math.log2(i + 1)))

if __name__ == "__main__":
    solve()

