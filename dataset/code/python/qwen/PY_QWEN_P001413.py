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
    unique_nums = [num for num, cnt in counter.items() if cnt == 1]
    
    if not unique_nums:
        print(-1)
    else:
        print(max(unique_nums))

solve()

