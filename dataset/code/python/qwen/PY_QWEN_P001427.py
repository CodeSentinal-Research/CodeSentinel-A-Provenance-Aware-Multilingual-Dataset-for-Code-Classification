import sys
from collections import Counter

def solve():
    n = int(sys.stdin.readline())
    
    digit_sums = Counter()
    for i in range(1, n + 1):
        s = sum(int(d) for d in str(i))
        digit_sums[s] += 1
        
    max_size = max(digit_sums.values())
    count = sum(1 for v in digit_sums.values() if v == max_size)
    
    print(count)

solve()

