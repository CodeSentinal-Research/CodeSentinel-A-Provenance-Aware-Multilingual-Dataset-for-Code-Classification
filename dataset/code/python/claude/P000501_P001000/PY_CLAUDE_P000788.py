
n=int(input());a=list(map(int,input().split()));k=int(input())
s=sum(a[:k]);best=s
for i in range(k,n): s+=a[i]-a[i-k];best=max(best,s)
print(best/k)
