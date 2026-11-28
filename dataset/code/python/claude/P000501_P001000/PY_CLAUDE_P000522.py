
n=int(input());a=list(map(int,input().split()))
print(*[sum(1 for j in range(i+1,n) if a[j]<a[i]) for i in range(n)])
