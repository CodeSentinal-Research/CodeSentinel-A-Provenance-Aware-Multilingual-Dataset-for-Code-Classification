import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    counter = Counter()
    pairs = 0
    for num in nums:
        pairs += counter[num ^ k]
        counter[num] += 1
        
    print(pairs)

solve()

