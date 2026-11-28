n = int(input())
m = int(input())
logs = [input().strip() for _ in range(m)]
res = [0] * n
stack = []
for log in logs:
    fid, typ, ts = log.split(':')
    fid, ts = int(fid), int(ts)
    if typ == 'start':
        if stack:
            res[stack[-1][0]] += ts - stack[-1][1]
        stack.append([fid, ts])
    else:
        res[fid] += ts - stack.pop()[1] + 1
        if stack:
            stack[-1][1] = ts + 1
print(" ".join(map(str, res)))
