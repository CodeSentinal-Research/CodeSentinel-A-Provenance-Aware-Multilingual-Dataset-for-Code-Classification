# problem title : Maximum Average Subarray
# A sliding window keeps the K-element sum in O(N) time.
n,k=map(int,input().split()); a=list(map(int,input().split())); w=sum(a[:k]); best=w
for i in range(k,n): w+=a[i]-a[i-k]; best=max(best,w)
print(best/k)
