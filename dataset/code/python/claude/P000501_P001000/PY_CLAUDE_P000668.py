
sz=int(input());a=list(map(int,input().split()));M=int(input());N=int(input())
res=[];i=0
while i<sz:
    res.extend(a[i:i+M]);i+=M+N
print(*res if res else [''])
