
n=int(input());a=list(map(int,input().split()))
for i in range(n-1):
    if i%2==0 and a[i]>a[i+1]: a[i],a[i+1]=a[i+1],a[i]
    elif i%2==1 and a[i]<a[i+1]: a[i],a[i+1]=a[i+1],a[i]
print(*a)
