
q=int(input());stk=[];min_stk=[]
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='push':
        v=int(cmd[1]);stk.append(v)
        min_stk.append(v if not min_stk else min(min_stk[-1],v))
    elif cmd[0]=='pop': stk.pop();min_stk.pop()
    elif cmd[0]=='top': print(stk[-1])
    elif cmd[0]=='getMin': print(min_stk[-1])
