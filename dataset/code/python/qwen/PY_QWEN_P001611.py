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
    
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + nums[i]
        
    dq = deque()
    min_len = float('inf')
    
    for i in range(n + 1):
        while dq and prefix_sum[i] - prefix_sum[dq[0]] >= k:
            min_len = min(min_len, i - dq.popleft())
        while dq and prefix_sum[dq[-1]] >= prefix_sum[i]:
            dq.pop()
        dq.append(i)
        
    print(min_len if min_len != float('inf') else -1)

solve()

