
n=int(input());a=list(map(int,input().split()));k=int(input())
a[k-1],a[n-k]=a[n-k],a[k-1]
print(*a)
