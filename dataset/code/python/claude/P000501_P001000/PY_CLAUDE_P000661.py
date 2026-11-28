
n=int(input());a=list(map(int,input().split()))
res=[]
for v in a:
    if not res or res[-1]!=v: res.append(v)
print(*res)
