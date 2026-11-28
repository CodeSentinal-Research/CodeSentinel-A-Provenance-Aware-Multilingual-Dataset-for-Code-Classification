
n=int(input());a=list(map(int,input().split()))
total=0
for i in range(n):
    mn=mx=a[i]
    for j in range(i,n):
        mn=min(mn,a[j]);mx=max(mx,a[j])
        total+=mx-mn
print(total)
