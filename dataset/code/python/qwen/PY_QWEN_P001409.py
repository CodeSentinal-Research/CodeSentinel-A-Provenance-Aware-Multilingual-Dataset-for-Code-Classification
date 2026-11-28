import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    groups = defaultdict(list)
    for i, num in enumerate(nums):
        groups[num].append(i)
        
    count = 0
    for indices in groups.values():
        m = len(indices)
        for i in range(m):
            for j in range(i + 1, m):
                if (indices[i] * indices[j]) % k == 0:
                    count += 1
                    
    print(count)

solve()

