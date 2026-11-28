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
    
    prefix_sum = 0
    counter = Counter()
    counter[0] = 1
    count = 0
    
    for num in nums:
        prefix_sum += num
        remainder = prefix_sum % k
        if remainder < 0:
            remainder += k
        if remainder in counter:
            count += counter[remainder]
        counter[remainder] += 1
        
    print(count)

solve()

