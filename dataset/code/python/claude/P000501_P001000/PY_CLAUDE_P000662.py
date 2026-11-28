
n=int(input());a=list(map(int,input().split()));k=int(input())
print(*a[:k][::-1],*a[k:])
