
a,b=input().split()
pa=[int(x) for x in a.split('.')];pb=[int(x) for x in b.split('.')]
n=max(len(pa),len(pb))
for i in range(n):
    va=pa[i] if i<len(pa) else 0;vb=pb[i] if i<len(pb) else 0
    if va<vb: print(-1);exit()
    elif va>vb: print(1);exit()
print(0)
