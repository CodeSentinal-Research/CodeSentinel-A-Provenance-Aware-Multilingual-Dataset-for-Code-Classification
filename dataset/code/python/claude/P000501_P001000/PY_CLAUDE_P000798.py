
n=int(input());a=list(map(int,input().split()))
pre={0:-1};s=0;best=0
for i,v in enumerate(a):
    s+=(1 if v==1 else -1)
    if s in pre: best=max(best,i-pre[s])
    else: pre[s]=i
print(best)
