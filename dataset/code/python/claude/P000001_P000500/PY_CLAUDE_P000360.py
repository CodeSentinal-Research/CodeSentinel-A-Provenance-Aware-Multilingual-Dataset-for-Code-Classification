
n=int(input());a=list(map(int,input().split()))
for i,x in enumerate(a):
    if x%2==0: print(i);exit()
print(-1)
