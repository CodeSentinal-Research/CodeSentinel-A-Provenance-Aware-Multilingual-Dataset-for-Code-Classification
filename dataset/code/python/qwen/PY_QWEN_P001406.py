import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    key = int(input_data[idx]); idx += 1
    
    next_counter = Counter()
    for i in range(n - 1):
        if nums[i] == key:
            next_counter[nums[i+1]] += 1
            
    if not next_counter:
        print(-1)
    else:
        max_freq = max(next_counter.values())
        candidates = [num for num, freq in next_counter.items() if freq == max_freq]
        print(min(candidates))

solve()

