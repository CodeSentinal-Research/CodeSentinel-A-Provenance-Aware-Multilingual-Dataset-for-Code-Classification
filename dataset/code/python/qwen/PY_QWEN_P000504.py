import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    m = int(input_data[1])
    logs = input_data[2:2+m]
    res = [0] * n
    stack = []
    for log in logs:
        parts = log.split(':')
        fid, typ, ts = int(parts[0]), parts[1], int(parts[2])
        if typ == 'start':
            if stack:
                res[stack[-1][0]] += ts - stack[-1][1]
            stack.append([fid, ts])
        else:
            res[fid] += ts - stack.pop()[1] + 1
            if stack:
                stack[-1][1] = ts + 1
    print(" ".join(map(str, res)))
solve()
