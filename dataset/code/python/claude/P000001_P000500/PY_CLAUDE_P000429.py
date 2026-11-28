
n,x=map(int,input().split())
a=list(map(int,input().split()))
for i,v in enumerate(a):
    if v==x: print(i);exit()
print(-1)
