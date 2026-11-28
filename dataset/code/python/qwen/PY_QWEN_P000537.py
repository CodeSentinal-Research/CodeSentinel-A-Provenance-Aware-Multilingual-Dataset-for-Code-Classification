import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:n+1]))
    k = int(input_data[n+1])
    q = deque()
    res = []
    for i in range(n):
        while q and q[0] < i - k + 1:
            q.popleft()
        while q and nums[q[-1]] < nums[i]:
            q.pop()
        q.append(i)
        if i >= k - 1:
            res.append(nums[q[0]])
    print(" ".join(map(str, res)))
solve()
