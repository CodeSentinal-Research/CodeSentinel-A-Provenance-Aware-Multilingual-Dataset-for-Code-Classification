
n=int(input());enc=list(map(int,input().split()));first=int(input())
res=[first]
for v in enc: res.append(res[-1]^v)
print(*res)
