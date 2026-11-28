
q=int(input());stk=[];prices=[]
for _ in range(q):
    p=int(input());span=1
    while stk and stk[-1][0]<=p: span+=stk.pop()[1]
    stk.append((p,span))
    print(span)
