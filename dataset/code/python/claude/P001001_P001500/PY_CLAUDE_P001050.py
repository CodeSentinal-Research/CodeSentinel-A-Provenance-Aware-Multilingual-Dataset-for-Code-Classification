
import heapq
n=int(input());a=list(map(int,input().split()))

for i in range(n//2-1,-1,-1):
    j=i
    while True:
        smallest=j;l=2*j+1;r=2*j+2
        if l<n and a[l]<a[smallest]: smallest=l
        if r<n and a[r]<a[smallest]: smallest=r
        if smallest==j: break
        a[j],a[smallest]=a[smallest],a[j];j=smallest
print(*a)
