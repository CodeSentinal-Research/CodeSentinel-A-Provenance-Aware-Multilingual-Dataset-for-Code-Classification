
from collections import OrderedDict
q=int(input());od=OrderedDict()
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='put': od[cmd[1]]=cmd[2]
    elif cmd[0]=='get': print(od.get(cmd[1],'Not found'))
    elif cmd[0]=='delete': od.pop(cmd[1],None)
    elif cmd[0]=='display': print(*['%s:%s'%(k,v) for k,v in od.items()])
