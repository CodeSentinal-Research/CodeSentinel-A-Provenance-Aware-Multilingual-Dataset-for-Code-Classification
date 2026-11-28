import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    grid = []
    idx = 1
    for _ in range(n):
        grid.append(list(map(int, input_data[idx:idx+n])))
        idx += n
    print("-1")
solve()
