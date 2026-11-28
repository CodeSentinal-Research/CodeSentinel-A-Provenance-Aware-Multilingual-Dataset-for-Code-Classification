import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    k = int(input_data[1])
    q = list(range(1, n + 1))
    idx = 0
    while len(q) > 1:
        idx = (idx + k - 1) % len(q)
        q.pop(idx)
    print(q[0])
solve()
