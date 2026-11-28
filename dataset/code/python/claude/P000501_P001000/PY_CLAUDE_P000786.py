
n=int(input());a=list(map(int,input().split()))
pre=[0]*(n+1);suf=[0]*(n+1)
for i in range(n): pre[i+1]=pre[i]+a[i]
for i in range(n-1,-1,-1): suf[i]=suf[i+1]+a[i]
print(*[abs(pre[i]-suf[i+1]) for i in range(n)])
