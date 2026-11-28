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
    
    left = 0
    max_len = 0
    counter = Counter()
    
    for right in range(n):
        counter[nums[right]] += 1
        while len(counter) > k:
            counter[nums[left]] -= 1
            if counter[nums[left]] == 0:
                del counter[nums[left]]
            left += 1
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

