import sys
from collections import deque, Counter
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    init = list(map(int, input_data[1:n+1]))
    q = int(input_data[n+1])
    ops = input_data[n+2:n+2+q*2]
    counts = Counter(init)
    order = deque(init)
    idx = 0
    for _ in range(q):
        op = ops[idx]; idx += 1
        if op == "showFirstUnique":
            while order and counts[order[0]] > 1:
                order.popleft()
            print(order[0] if order else -1)
        elif op == "add":
            val = int(ops[idx]); idx += 1
            counts[val] += 1
            order.append(val)
solve()
