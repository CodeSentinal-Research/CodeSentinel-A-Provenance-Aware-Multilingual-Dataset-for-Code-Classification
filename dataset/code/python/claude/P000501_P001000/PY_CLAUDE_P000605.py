
n=int(input());a=list(map(int,input().split()))
res=[];mx=0
for v in reversed(a):
    if v>=mx: res.append(v);mx=v
print(*reversed(res))
