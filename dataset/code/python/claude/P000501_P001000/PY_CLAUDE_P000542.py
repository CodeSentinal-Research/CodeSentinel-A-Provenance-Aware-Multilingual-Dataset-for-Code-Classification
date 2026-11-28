
from collections import deque
q=int(input());L=deque();R=deque()
def balance():
    """
    Design Front Middle Back Queue: balance
    """
    while len(L)>len(R)+1: R.appendleft(L.pop())
    while len(R)>len(L): L.append(R.popleft())
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='pushFront': L.appendleft(int(cmd[1]));balance()
    elif cmd[0]=='pushMiddle':
        v=int(cmd[1])
        if len(L)<=len(R): L.append(v)
        else: R.appendleft(L.pop());L.append(v)
        balance()
    elif cmd[0]=='pushBack': R.append(int(cmd[1]));balance()
    elif cmd[0]=='popFront':
        if not L and not R: print(-1)
        else: print(L.popleft() if L else R.popleft());balance()
    elif cmd[0]=='popMiddle':
        if not L and not R: print(-1)
        else: print(L.pop() if len(L)>len(R) else R.popleft());balance()
    elif cmd[0]=='popBack':
        if not L and not R: print(-1)
        else: print(R.pop() if R else L.pop());balance()
