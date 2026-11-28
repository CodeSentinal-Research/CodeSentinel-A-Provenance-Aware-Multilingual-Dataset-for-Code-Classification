
q=int(input());stk=[];mstk=[]
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='push':
        v=int(cmd[1]);stk.append(v)
        mstk.append(v if not mstk else min(mstk[-1],v))
    elif cmd[0]=='pop': stk.pop();mstk.pop()
    elif cmd[0]=='top': print(stk[-1])
    elif cmd[0]=='getMin': print(mstk[-1])
