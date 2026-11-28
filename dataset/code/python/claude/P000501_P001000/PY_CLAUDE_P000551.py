
from collections import deque
n=int(input());q=deque(['1']);res=[]
for _ in range(n):
    s=q.popleft();res.append(s)
    q.append(s+'0');q.append(s+'1')
print(*res)
