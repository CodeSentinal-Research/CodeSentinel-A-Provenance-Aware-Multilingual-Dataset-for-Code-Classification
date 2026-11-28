# problem title : Number of Matching Subsequences
# Precompute positions in S and advance each word through those positions.
from bisect import bisect_right
s=input(); words=input().split(); pos={}
for i,ch in enumerate(s):pos.setdefault(ch,[]).append(i)
ans=0
for w in words:
    cur=-1;ok=True
    for ch in w:
        arr=pos.get(ch,[]); k=bisect_right(arr,cur)
        if k==len(arr):ok=False;break
        cur=arr[k]
    ans+=ok
print(ans)
