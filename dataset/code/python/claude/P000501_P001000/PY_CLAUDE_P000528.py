
n=int(input());a=list(map(int,input().split()))
ans=[-1]*n;stk=[]
for i in range(2*n):
    while stk and a[stk[-1]]<a[i%n]: ans[stk.pop()]=a[i%n]
    if i<n: stk.append(i)
print(*ans)
