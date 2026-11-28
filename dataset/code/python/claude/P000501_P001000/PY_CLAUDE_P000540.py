
from collections import deque
q=int(input());queue=deque()
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='enqueue': queue.append(int(cmd[1]))
    elif cmd[0]=='dequeue': print(queue.popleft())
    elif cmd[0]=='front': print(queue[0])
    elif cmd[0]=='size': print(len(queue))
    elif cmd[0]=='isEmpty': print(len(queue)==0)
