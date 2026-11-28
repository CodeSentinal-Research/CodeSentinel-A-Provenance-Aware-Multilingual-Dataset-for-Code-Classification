
n=int(input());a=list(map(int,input().split()));k=int(input())
k%=n;print(*(a[-k:]+a[:-k]) if k else *a)
