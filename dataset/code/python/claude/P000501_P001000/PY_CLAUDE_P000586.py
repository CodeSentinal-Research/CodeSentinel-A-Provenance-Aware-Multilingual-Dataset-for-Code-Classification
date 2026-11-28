
n=int(input());a=list(map(int,input().split()));k=int(input())
res=[]
for i in range(0,n,k):
    chunk=a[i:i+k]
    if len(chunk)==k: res.extend(reversed(chunk))
    else: res.extend(chunk)
print(*res)
