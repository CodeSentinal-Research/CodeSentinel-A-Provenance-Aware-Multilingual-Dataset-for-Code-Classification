# problem title : Remove Invalid Parentheses
# BFS removes the minimum number of parentheses; the first valid level is optimal.
s=input(); level={s}; out=[]
def valid(x):
    bal=0
    for ch in x:
        bal += ch=='('; bal -= ch==')'
        if bal<0:return False
    return bal==0
while level:
    good=[x for x in level if valid(x)]
    if good: out=sorted(set(good)); break
    nxt=set()
    for x in level:
        for i,ch in enumerate(x):
            if ch in '()': nxt.add(x[:i]+x[i+1:])
    level=nxt
print(*out,sep='\n')
