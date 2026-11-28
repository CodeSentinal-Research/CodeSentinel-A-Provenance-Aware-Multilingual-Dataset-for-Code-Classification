
n=int(input());a=list(map(int,input().split()))
seen=set()
for x in a:
    if x in seen: print(x);exit()
    seen.add(x)
print(-1)
