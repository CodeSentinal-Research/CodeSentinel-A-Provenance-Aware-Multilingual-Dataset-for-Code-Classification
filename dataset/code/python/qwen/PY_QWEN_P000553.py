import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    board = []
    idx = 1
    for _ in range(n):
        board.append(list(map(int, input_data[idx:idx+n])))
        idx += n
    board.reverse()
    def get_pos(s):
        s -= 1
        r, c = divmod(s, n)
        if r % 2 == 1: c = n - 1 - c
        return r, c
    q = deque([(1, 0)])
    vis = {1}
    while q:
        curr, steps = q.popleft()
        if curr == n * n:
            print(steps)
            return
        for i in range(1, 7):
            nxt = curr + i
            if nxt <= n * n:
                r, c = get_pos(nxt)
                if board[r][c] != -1:
                    nxt = board[r][c]
                if nxt not in vis:
                    vis.add(nxt)
                    q.append((nxt, steps + 1))
    print(-1)
solve()
