
n=int(input());a=list(map(int,input().split()))
stk=[];k3=float('-inf')
for v in reversed(a):
    if v<k3: print('true');exit()
    while stk and stk[-1]<v: k3=stk.pop()
    stk.append(v)
print('false')
