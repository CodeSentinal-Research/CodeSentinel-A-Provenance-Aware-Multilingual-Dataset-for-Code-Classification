
from collections import deque
vals = input().split()
n = len(vals)
if not vals or vals[0] == 'null':
    exit()
nodes = [None if v == 'null' else int(v) for v in vals]
q = deque([(0, 0, 0)])
top = {}
while q:
    idx, lev, hd = q.popleft()
    if idx >= n or nodes[idx] is None:
        continue
    if hd not in top:
        top[hd] = nodes[idx]
    l, r = 2*idx+1, 2*idx+2
    if l < n: q.append((l, lev+1, hd-1))
    if r < n: q.append((r, lev+1, hd+1))
print(*[top[k] for k in sorted(top)])
