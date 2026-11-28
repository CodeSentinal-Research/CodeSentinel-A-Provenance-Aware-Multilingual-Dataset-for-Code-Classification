
n=int(input());a=sorted(map(int,input().split()))
res=set()
for i in range(1<<n):
    sub=tuple(a[j] for j in range(n) if i>>j&1)
    res.add(sub)
for r in sorted(res): print(*r if r else ['{}'])
