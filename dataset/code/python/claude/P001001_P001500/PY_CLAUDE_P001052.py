
import heapq
n=int(input());a=list(map(int,input().split()))

result=a[:]
for i in range(n//2-1,-1,-1):
    j=i
    while True:
        s=j;l=2*j+1;r=2*j+2
        if l<n and result[l]<result[s]: s=l
        if r<n and result[r]<result[s]: s=r
        if s==j: break
        result[j],result[s]=result[s],result[j];j=s
print(*result)
