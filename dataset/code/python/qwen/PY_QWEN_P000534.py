s = input().strip()
from collections import deque
q = deque(list(s))
r = s.count('R')
d = s.count('D')
while r > 0 and d > 0:
    c = q.popleft()
    if c == 'R':
        d -= 1
        q.append('R')
    else:
        r -= 1
        q.append('D')
print("Radiant" if r > 0 else "Dire")
