
n=int(input());a=list(map(int,input().split()))
res=[]
for i in range(1<<n):
    sub=[a[j] for j in range(n) if i>>j&1]
    if sub: res.append(sub)
for r in res: print(*r)
