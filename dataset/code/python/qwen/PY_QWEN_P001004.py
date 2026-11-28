import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if n <= 0:
        print(0)
    else:
        # Height of a complete binary tree with N nodes is floor(log2(N))
        print(math.floor(math.log2(n)))

if __name__ == "__main__":
    solve()

