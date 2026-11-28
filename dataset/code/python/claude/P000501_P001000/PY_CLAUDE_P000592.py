
n=int(input());a=list(map(int,input().split()));val=int(input())
res=[v for v in a if v!=val]
print(*res if res else [''])
