import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    counter = Counter(nums)
    max_len = 0
    
    for num in counter:
        if num + 1 in counter:
            max_len = max(max_len, counter[num] + counter[num + 1])
            
    print(max_len if max_len > 0 else 0)

solve()

