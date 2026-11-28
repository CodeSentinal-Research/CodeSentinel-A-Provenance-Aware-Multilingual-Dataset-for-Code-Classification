
n=int(input());a=list(map(int,input().split()))
res=[];i=0;g=1
while i<n:
    chunk=a[i:i+g]
    if len(chunk)%2==0: chunk=chunk[::-1]
    res.extend(chunk);i+=g;g+=1
print(*res)
