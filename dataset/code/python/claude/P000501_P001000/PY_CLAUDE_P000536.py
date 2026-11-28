
q=int(input())
from collections import deque
hits=deque()
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='hit': hits.append(int(cmd[1]))
    else:
        t=int(cmd[1])
        while hits and hits[0]<=t-300: hits.popleft()
        print(len(hits))
