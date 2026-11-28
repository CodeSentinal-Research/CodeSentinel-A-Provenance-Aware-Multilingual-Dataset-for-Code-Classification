
n=int(input());t=list(map(int,input().split()))
ans=[0]*n;stk=[]
for i in range(n):
    while stk and t[stk[-1]]<t[i]:
        ans[stk.pop()]=i-stk[-1] if stk else i
    stk.append(i)

ans=[0]*n;stk=[]
for i in range(n):
    while stk and t[stk[-1]]<t[i]:
        j=stk.pop();ans[j]=i-j
    stk.append(i)
print(*ans)
