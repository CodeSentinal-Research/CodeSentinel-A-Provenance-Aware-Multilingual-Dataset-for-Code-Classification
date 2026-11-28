
q=int(input());terms={}
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='addTerm': coef,exp=int(cmd[1]),int(cmd[2]);terms[exp]=terms.get(exp,0)+coef
    elif cmd[0]=='evaluate': x=float(cmd[1]);print(sum(c*(x**e) for e,c in terms.items()))
    elif cmd[0]=='display': print(' + '.join('%dx^%d'%(c,e) for e,c in sorted(terms.items(),reverse=True)))
