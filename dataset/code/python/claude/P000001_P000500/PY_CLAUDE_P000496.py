
n=int(input());a=list(map(int,input().split()))
MOD=10**9+7
stk=[];res=0
for i in range(n+1):
    while stk and (i==n or a[stk[-1]]>=a[i]):
        mid=stk.pop()
        left=stk[-1] if stk else -1
        right=i
        res=(res+a[mid]*(mid-left)*(right-mid))%MOD
    stk.append(i)
print(res)
