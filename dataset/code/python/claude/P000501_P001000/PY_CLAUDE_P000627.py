
n=int(input());a=list(map(int,input().split()));k=int(input())
res=[]
for i in range(0,n,k): chunk=a[i:i+k];res.extend(reversed(chunk))
print(*res)
