import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:n+1]))
    k = int(input_data[n+1])
    dp = nums[:]
    q = deque([0])
    for i in range(1, n):
        while q and q[0] < i - k:
            q.popleft()
        dp[i] = nums[i] + dp[q[0]]
        while q and dp[q[-1]] <= dp[i]:
            q.pop()
        q.append(i)
    print(dp[-1])
solve()
