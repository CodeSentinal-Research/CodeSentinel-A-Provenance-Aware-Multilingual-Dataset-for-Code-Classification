
n=int(input());senate=input().strip()
from collections import deque
R=deque();D=deque()
for i,c in enumerate(senate):
    if c=='R': R.append(i)
    else: D.append(i)
while R and D:
    r,d=R.popleft(),D.popleft()
    if r<d: R.append(r+n)
    else: D.append(d+n)
print('Radiant' if R else 'Dire')
