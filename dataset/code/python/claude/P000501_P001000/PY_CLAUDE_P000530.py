
import collections
q=int(input());buf=collections.deque()
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='enQueue': buf.append(int(cmd[1]));print('true')
    elif cmd[0]=='deQueue':
        if buf: buf.popleft();print('true')
        else: print('false')
    elif cmd[0]=='Front': print(buf[0] if buf else -1)
    elif cmd[0]=='Rear': print(buf[-1] if buf else -1)
    elif cmd[0]=='isEmpty': print(len(buf)==0)
    elif cmd[0]=='isFull': print('false')
