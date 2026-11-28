import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    counter = Counter(nums)
    freqs = list(counter.values())
    
    if len(freqs) == len(set(freqs)):
        print("YES")
    else:
        print("NO")

solve()

