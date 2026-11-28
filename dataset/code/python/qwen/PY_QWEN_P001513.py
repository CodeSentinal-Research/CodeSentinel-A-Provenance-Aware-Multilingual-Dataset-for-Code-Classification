import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    total_distinct = len(set(nums))
    left = 0
    count = 0
    window_counts = Counter()
    
    for right in range(n):
        window_counts[nums[right]] += 1
        while len(window_counts) == total_distinct:
            count += n - right
            window_counts[nums[left]] -= 1
            if window_counts[nums[left]] == 0:
                del window_counts[nums[left]]
            left += 1
            
    print(count)

solve()

