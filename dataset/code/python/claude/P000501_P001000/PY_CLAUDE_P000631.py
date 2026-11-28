
n=int(input());a=list(map(int,input().split()));k=int(input())
k%=n if n else 1
print(*(a[-k:]+a[:-k]) if k else *a)
