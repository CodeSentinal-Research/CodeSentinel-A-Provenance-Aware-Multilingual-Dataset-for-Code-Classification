
n=int(input());a=list(map(int,input().split()));stk=[]
for x in a:
    alive=True
    while alive and x<0 and stk and stk[-1]>0:
        if stk[-1]<-x: stk.pop()
        elif stk[-1]==-x: stk.pop();alive=False
        else: alive=False
    if alive: stk.append(x)
print(*stk)
