
from collections import deque
vals = input().split()
n = len(vals)
if not vals or vals[0] == 'null':
    exit()
nodes = [None if v == 'null' else int(v) for v in vals]
q = deque([(0, 0)])
level_right = {}
while q:
    idx, lev = q.popleft()
    if idx >= n or nodes[idx] is None:
        continue
    level_right[lev] = nodes[idx]
    l, r = 2*idx+1, 2*idx+2
    if l < n: q.append((l, lev+1))
    if r < n: q.append((r, lev+1))
print(*[level_right[k] for k in sorted(level_right)])
