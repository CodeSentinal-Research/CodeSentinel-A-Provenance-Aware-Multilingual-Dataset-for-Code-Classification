
from collections import deque
q=int(input());dq=deque();cap=int(input()) if False else float('inf')
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='insertFront': dq.appendleft(int(cmd[1]))
    elif cmd[0]=='insertLast': dq.append(int(cmd[1]))
    elif cmd[0]=='deleteFront': dq.popleft() if dq else None
    elif cmd[0]=='deleteLast': dq.pop() if dq else None
    elif cmd[0]=='getFront': print(dq[0] if dq else -1)
    elif cmd[0]=='getRear': print(dq[-1] if dq else -1)
    elif cmd[0]=='isEmpty': print(len(dq)==0)
    elif cmd[0]=='isFull': print('false')
