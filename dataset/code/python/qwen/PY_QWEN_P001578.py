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
    
    counter = Counter(nums[:k])
    count = 1 if len(counter) == k else 0
    
    for i in range(k, n):
        counter[nums[i]] += 1
        counter[nums[i-k]] -= 1
        if counter[nums[i-k]] == 0:
            del counter[nums[i-k]]
        if len(counter) == k:
            count += 1
            
    print(count)

solve()

