
n=int(input());h=list(map(int,input().split()))
ans=[0]*n;stk=[]
for i in range(n-1,-1,-1):
    cnt=0
    while stk and stk[-1]<h[i]: stk.pop();cnt+=1
    if stk: cnt+=1
    ans[i]=cnt;stk.append(h[i])
print(*ans)
