import sys
from sortedcontainers import SortedList
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    q = int(input_data[0])
    idx = 1
    sl = SortedList()
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op.startswith("push"):
            val = int(input_data[idx]); idx += 1
            sl.add(val)
        elif op.startswith("pop"):
            print(sl.pop(0) if sl else -1)
solve()
