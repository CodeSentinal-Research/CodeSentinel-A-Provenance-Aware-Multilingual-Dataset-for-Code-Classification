
n=int(input());a=list(map(int,input().split()))

total=sum(a);left=0
for i,v in enumerate(a):
    if left == total-left-v: print(i);exit()
    left+=v
print(-1)
