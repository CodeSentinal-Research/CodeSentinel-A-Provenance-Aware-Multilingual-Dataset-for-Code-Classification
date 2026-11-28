import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    dq = deque()
    results = []
    
    for i in range(n):
        if dq and dq[0] < i - k + 1:
            dq.popleft()
        while dq and nums[dq[-1]] >= nums[i]:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            results.append(nums[dq[0]])
            
    print(*results)

solve()

