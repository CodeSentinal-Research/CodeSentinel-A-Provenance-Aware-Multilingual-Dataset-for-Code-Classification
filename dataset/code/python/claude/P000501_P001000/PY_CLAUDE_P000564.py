
from collections import deque
begin=input().strip();end=input().strip();n=int(input());wl=set(input().strip() for _ in range(n))
if end not in wl: print([]);exit()
res=[];q=deque([[begin]]);visited=set()
found_len=None
while q:
    path=q.popleft()
    if found_len and len(path)>found_len: break
    word=path[-1]
    for i in range(len(word)):
        for c in 'abcdefghijklmnopqrstuvwxyz':
            nw=word[:i]+c+word[i+1:]
            if nw in wl:
                if nw==end:
                    res.append(path+[nw]);found_len=len(path)+1
                elif nw not in visited: q.append(path+[nw])
    visited.add(word)
for p in res: print(p)
