
from collections import deque
q=int(input())
queue=deque()
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='push': queue.append(int(cmd[1]));queue.rotate(-1);for _ in range(len(queue)-1): queue.rotate(-1)
    elif cmd[0]=='pop': print(queue.popleft())
    elif cmd[0]=='top': print(queue[0])
    elif cmd[0]=='empty': print(len(queue)==0)
