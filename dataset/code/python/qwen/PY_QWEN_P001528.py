import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    left = 0
    count = 0
    window_counts = Counter()
    
    for right in range(n):
        window_counts[nums[right]] += 1
        while len(window_counts) > k:
            window_counts[nums[left]] -= 1
            if window_counts[nums[left]] == 0:
                del window_counts[nums[left]]
            left += 1
        count += right - left + 1
        
    print(count)

solve()

