
n=int(input());a=list(map(int,input().split()))
print(max(a[i]+a[n-1-i] for i in range(n//2)))
