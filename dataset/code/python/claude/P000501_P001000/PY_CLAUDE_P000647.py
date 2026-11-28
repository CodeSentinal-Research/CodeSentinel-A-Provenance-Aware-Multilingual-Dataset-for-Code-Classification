
q=int(input());playlist=[]
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='add': playlist.append(' '.join(cmd[1:]))
    elif cmd[0]=='remove': playlist=[s for s in playlist if s!=' '.join(cmd[1:])]
    elif cmd[0]=='query': print(playlist[int(cmd[1])-1] if 0<int(cmd[1])<=len(playlist) else 'Not found')
