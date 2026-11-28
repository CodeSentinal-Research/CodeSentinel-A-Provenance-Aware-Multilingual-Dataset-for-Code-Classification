import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    prefix_xor = 0
    counter = Counter()
    counter[0] = 1
    pairs = 0
    
    for num in nums:
        prefix_xor ^= num
        pairs += counter[prefix_xor]
        counter[prefix_xor] += 1
        
    print(pairs)

solve()

