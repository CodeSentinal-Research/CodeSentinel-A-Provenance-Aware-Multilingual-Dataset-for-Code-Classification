
from collections import deque
begin=input().strip();end=input().strip();n=int(input());wl=set(input().strip() for _ in range(n))
if end not in wl: print(0);exit()
q=deque([(begin,1)]);visited={begin}
while q:
    word,length=q.popleft()
    for i in range(len(word)):
        for c in 'abcdefghijklmnopqrstuvwxyz':
            nw=word[:i]+c+word[i+1:]
            if nw==end: print(length+1);exit()
            if nw in wl and nw not in visited: visited.add(nw);q.append((nw,length+1))
print(0)
