
n=int(input());a=list(map(int,input().split()));x=int(input())
for i,v in enumerate(a):
    if v<x: print(i);exit()
print(-1)
