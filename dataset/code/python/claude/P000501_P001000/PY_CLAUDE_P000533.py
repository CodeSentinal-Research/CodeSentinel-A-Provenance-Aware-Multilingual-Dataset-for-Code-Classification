
size=int(input());q=int(input())
from collections import deque
window=deque();total=0
for _ in range(q):
    v=int(input())
    if len(window)==size: total-=window.popleft()
    window.append(v);total+=v
    print(total/len(window))
