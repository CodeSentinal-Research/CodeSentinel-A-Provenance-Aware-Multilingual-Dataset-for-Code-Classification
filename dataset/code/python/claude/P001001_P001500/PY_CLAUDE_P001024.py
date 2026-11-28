
n=int(input());a=list(map(int,input().split()));i=int(input())
l,r=2*i+1,2*i+2
if l<n and r<n: print(a[l],a[r])
elif l<n: print(a[l])
else: print(-1)
