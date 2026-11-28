import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    window_counts = Counter(nums[:k])
    results = [len(window_counts)]
    
    for i in range(k, n):
        window_counts[nums[i]] += 1
        window_counts[nums[i-k]] -= 1
        if window_counts[nums[i-k]] == 0:
            del window_counts[nums[i-k]]
        results.append(len(window_counts))
        
    print(" ".join(map(str, results)))

solve()

