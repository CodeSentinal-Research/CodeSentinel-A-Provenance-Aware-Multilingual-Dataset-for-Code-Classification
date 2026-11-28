
n=int(input())
a=list(map(int,input().split()))
res=[]
for i in range(n):
    cnt=sum(1 for j in range(i+1,n) if a[j]<a[i])
    res.append(cnt)
print(*res)
