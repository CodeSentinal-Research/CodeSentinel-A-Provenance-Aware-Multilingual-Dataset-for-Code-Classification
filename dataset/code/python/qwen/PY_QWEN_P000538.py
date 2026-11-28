import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:n+1]))
    k = int(input_data[n+1])
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i+1] = prefix[i] + nums[i]
    q = deque()
    ans = float('inf')
    for i in range(n + 1):
        while q and prefix[i] - prefix[q[0]] >= k:
            ans = min(ans, i - q.popleft())
        while q and prefix[q[-1]] >= prefix[i]:
            q.pop()
        q.append(i)
    print(ans if ans != float('inf') else -1)
solve()
