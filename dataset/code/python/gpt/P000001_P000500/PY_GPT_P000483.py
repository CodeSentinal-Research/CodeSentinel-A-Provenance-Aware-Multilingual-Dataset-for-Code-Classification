# problem title : Implement Stack Using Queues
# Two queues can implement a stack by rotating old elements behind the newest one.
from collections import deque
q=deque();out=[]
for _ in range(int(input())):
 p=input().split();op=p[0]
 if op=='push':
  q.append(p[1]);q.rotate(1)
 elif op=='pop': out.append(q.popleft() if q else '-1')
 elif op=='top': out.append(q[0] if q else '-1')
print('\n'.join(out))
