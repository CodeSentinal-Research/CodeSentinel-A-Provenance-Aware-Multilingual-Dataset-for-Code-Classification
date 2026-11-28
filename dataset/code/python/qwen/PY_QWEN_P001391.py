import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    prefix_sum = 0
    count_map = defaultdict(int)
    count_map[0] = 1
    total_count = 0
    
    for num in nums:
        prefix_sum += num
        if (prefix_sum - k) in count_map:
            total_count += count_map[prefix_sum - k]
        count_map[prefix_sum] += 1
        
    print(total_count)

solve()

