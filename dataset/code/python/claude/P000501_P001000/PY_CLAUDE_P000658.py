
q=int(input());wins={};cur_win=0
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='visit': wins.setdefault(cur_win,[]).append(cmd[1])
    elif cmd[0]=='back':
        w=wins.get(cur_win,[])
        if len(w)>1: wins[cur_win]=w[:-1]
        print(wins.get(cur_win,[''])[-1])
    elif cmd[0]=='current': print(wins.get(cur_win,[''])[-1])
    elif cmd[0]=='switch': cur_win=int(cmd[1])
