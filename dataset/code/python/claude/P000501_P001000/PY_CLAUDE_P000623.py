
n=int(input());a=list(map(int,input().split()));k=int(input())
res=[];i=0;rev=True
while i<n:
    chunk=a[i:i+k]
    if rev: chunk=chunk[::-1]
    res.extend(chunk);i+=k;rev=not rev
print(*res)
