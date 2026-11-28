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
        remainder = prefix_sum % k
        # Handle negative remainders
        if remainder < 0:
            remainder += k
            
        if remainder in count_map:
            total_count += count_map[remainder]
        count_map[remainder] += 1
        
    print(total_count)

solve()

