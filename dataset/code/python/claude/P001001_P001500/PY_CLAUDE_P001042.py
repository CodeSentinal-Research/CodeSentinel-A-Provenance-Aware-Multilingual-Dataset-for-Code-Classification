
n=int(input());a=list(map(int,input().split()))
leaves=[a[i] for i in range(n//2,n)]
print(*leaves)
