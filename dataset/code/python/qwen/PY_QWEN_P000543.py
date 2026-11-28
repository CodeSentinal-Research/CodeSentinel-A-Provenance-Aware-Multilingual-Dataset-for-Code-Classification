import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    q = int(input_data[0])
    idx = 1
    intervals = []
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "addNum":
            val = int(input_data[idx]); idx += 1
            intervals.append(val)
        elif op == "getIntervals":
            intervals.sort()
            res = []
            for v in intervals:
                if not res or res[-1][1] + 1 < v:
                    res.append([v, v])
                else:
                    res[-1][1] = v
            print(" ".join(f"[{x},{y}]" for x, y in res))
solve()
