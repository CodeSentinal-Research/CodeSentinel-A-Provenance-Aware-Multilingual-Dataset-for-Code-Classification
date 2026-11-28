
q=int(input())
tabs=[];cur=-1
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='open': tabs.append(cmd[1]);cur=len(tabs)-1
    elif cmd[0]=='close':
        if tabs: tabs.pop(cur);cur=min(cur,len(tabs)-1)
    elif cmd[0]=='switch': cur=int(cmd[1])
    elif cmd[0]=='current': print(tabs[cur] if tabs else 'None')
