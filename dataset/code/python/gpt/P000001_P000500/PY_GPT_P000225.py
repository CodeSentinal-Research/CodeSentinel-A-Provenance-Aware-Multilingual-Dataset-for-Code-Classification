# problem title : Minimum Swaps to Sort
# Each permutation cycle of length L needs L-1 swaps to become sorted.
n=int(input()); a=list(map(int,input().split())); pos={v:i for i,v in enumerate(sorted(a))}; seen=[False]*n; ans=0
for i in range(n):
    if seen[i] or pos[a[i]]==i: continue
    j=i; size=0
    while not seen[j]: seen[j]=True; size+=1; j=pos[a[j]]
    ans+=size-1
print(ans)
