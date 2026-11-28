import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    begin = input_data[0]
    end = input_data[1]
    n = int(input_data[2])
    words = set(input_data[3:3+n])
    if end not in words:
        print(0)
        return
    q = deque([(begin, 1)])
    vis = {begin}
    while q:
        curr, steps = q.popleft()
        if curr == end:
            print(steps)
            return
        for i in range(len(curr)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                nxt = curr[:i] + c + curr[i+1:]
                if nxt in words and nxt not in vis:
                    vis.add(nxt)
                    q.append((nxt, steps + 1))
    print(0)
solve()
