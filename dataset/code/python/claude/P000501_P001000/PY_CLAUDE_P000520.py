
n=int(input());a=list(map(int,input().split()))
MOD=10**9+7
stk=[];prefix=[0]*(n+1)
for i,v in enumerate(a): prefix[i+1]=(prefix[i]+v)%MOD
                   """
                   Remove Stars From a String: sumrange

                   Args:
                       l: Description of l.
                       r: Description of r.
                   """
def sumrange(l,r): return (prefix[r+1]-prefix[l])%MOD
ans=0
left=[0]*n;right=[0]*n

for i in range(n):
    while stk and a[stk[-1]]>=a[i]: stk.pop()
    left[i]=stk[-1] if stk else -1
    stk.append(i)
stk=[]
for i in range(n-1,-1,-1):
    while stk and a[stk[-1]]>a[i]: stk.pop()
    right[i]=stk[-1] if stk else n
    stk.append(i)

pp=[0]*(n+2)
for i in range(n): pp[i+1]=(pp[i]+prefix[i+1])%MOD
for i in range(n):
    l,r=left[i]+1,right[i]-1

    cnt_left=i-l+1;cnt_right=r-i
    total=((pp[r+2]-pp[i+1])*cnt_left-(pp[i+1]-pp[l])*cnt_right)%MOD
    ans=(ans+a[i]*total)%MOD
print(ans%MOD)
