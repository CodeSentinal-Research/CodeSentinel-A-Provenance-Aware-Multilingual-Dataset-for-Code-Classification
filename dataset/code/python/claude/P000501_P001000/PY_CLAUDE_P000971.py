
a,b=int(input()),int(input());f0,f1=int(input()),int(input());n=int(input())
if n==0: print(f0);exit()
if n==1: print(f1);exit()
prev,cur=f0,f1
for _ in range(n-1): prev,cur=cur,a*cur+b*prev
print(cur)
