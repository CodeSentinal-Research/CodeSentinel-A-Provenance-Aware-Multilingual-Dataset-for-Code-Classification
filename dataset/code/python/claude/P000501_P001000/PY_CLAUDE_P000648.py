
q=int(input());doc='';undo_stk=[];redo_stk=[]
for _ in range(q):
    cmd=input().split(maxsplit=1)
    if cmd[0]=='type': undo_stk.append(doc);doc+=cmd[1] if len(cmd)>1 else '';redo_stk.clear()
    elif cmd[0]=='undo':
        if undo_stk: redo_stk.append(doc);doc=undo_stk.pop()
    elif cmd[0]=='redo':
        if redo_stk: undo_stk.append(doc);doc=redo_stk.pop()
    elif cmd[0]=='print': print(doc)
