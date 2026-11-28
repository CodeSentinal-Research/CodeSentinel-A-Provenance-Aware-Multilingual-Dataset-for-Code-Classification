
n=int(input());a=list(map(int,input().split()));p=int(input())
r=sum(a)%p
if r==0: print(0);exit()
pre={0:-1};s=0;best=n
for i,v in enumerate(a):
    s=(s+v)%p
    if (s-r)%p in pre: best=min(best,i-pre[(s-r)%p])
    pre[s]=i
print(-1 if best==n else best)
