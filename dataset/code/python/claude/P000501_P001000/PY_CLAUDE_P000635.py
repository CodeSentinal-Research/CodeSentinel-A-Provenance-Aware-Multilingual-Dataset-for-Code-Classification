
n=int(input());a=list(map(int,input().split()));g=int(input());groups=list(map(int,input().split()))
res=[];i=0
for sz in groups:
    chunk=a[i:i+sz];res.extend(reversed(chunk));i+=sz
res.extend(a[i:])
print(*res)
