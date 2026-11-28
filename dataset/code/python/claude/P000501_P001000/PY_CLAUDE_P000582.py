
n=int(input());a=list(map(int,input().split()))
seen=set();res=[]
for v in a:
    if v not in seen: seen.add(v);res.append(v)
print(*res)
