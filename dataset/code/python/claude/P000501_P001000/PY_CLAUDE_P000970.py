
n=int(input())
a,b,c=0,1,1
if n==1: print(0);exit()
if n==2: print(1);exit()
if n==3: print(1);exit()
for _ in range(n-3): a,b,c=b,c,a+b+c
print(c)
