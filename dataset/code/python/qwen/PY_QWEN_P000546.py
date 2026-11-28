import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    s = input_data[0]
    minJ = int(input_data[1])
    maxJ = int(input_data[2])
    n = len(s)
    if s[0] == '1' or s[-1] == '1':
        print("false")
        return
    q = deque([0])
    vis = [False] * n
    vis[0] = True
    while q:
        i = q.popleft()
        if i == n - 1:
            print("true")
            return
        for j in range(max(i + minJ, 0), min(i + maxJ + 1, n)):
            if s[j] == '0' and not vis[j]:
                vis[j] = True
                q.append(j)
    print("false")
solve()
