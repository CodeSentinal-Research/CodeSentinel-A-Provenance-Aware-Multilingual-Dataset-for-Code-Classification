
n=int(input());a=list(map(int,input().split()));k=int(input())
base,rem=n//k,n%k;res=[];i=0
for j in range(k):
    sz=base+(1 if j<rem else 0)
    print(*a[i:i+sz] if a[i:i+sz] else ['[]'])
    i+=sz
