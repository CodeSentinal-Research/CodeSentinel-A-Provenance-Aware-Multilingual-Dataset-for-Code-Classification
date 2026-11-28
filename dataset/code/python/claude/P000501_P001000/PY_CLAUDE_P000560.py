
from collections import deque
n=int(input());q=list(map(int,input().split()))
half=n//2;first=q[:half];second=q[half:]
result=[]
for a,b in zip(first,second): result.append(a);result.append(b)
print(*result)
