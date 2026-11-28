import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    s = input_data[0]
    k = int(input_data[1])
    
    counter = Counter(s)
    odd_count = sum(1 for c in counter.values() if c % 2 != 0)
    
    if odd_count > k:
        print("NO")
    else:
        print("YES")

if __name__ == "__main__":
    solve()

