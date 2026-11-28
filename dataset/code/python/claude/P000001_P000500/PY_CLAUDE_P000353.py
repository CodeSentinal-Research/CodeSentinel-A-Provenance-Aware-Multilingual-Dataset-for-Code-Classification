
n=int(input());a=list(map(int,input().split()));x=int(input())
idx=-1
for i,v in enumerate(a):
    if v==x: idx=i
print(idx)
