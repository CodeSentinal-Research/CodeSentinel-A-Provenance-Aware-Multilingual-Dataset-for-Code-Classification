

q=int(input());doc='';cursor=len(doc)
for _ in range(q):
    cmd=input().split(maxsplit=1)
    if cmd[0]=='insert':
        ch=cmd[1] if len(cmd)>1 else ''
        doc=doc[:cursor]+ch+doc[cursor:];cursor+=len(ch)
    elif cmd[0]=='delete':
        if cursor>0: doc=doc[:cursor-1]+doc[cursor:];cursor-=1
    elif cmd[0]=='moveCursor': cursor=int(cmd[1])
    elif cmd[0]=='print': print(doc)
