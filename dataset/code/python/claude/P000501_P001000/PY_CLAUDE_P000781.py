
n=int(input());a=list(map(int,input().split()))
s=0;res=[]
for v in a: s+=v;res.append(s)
print(*res)
