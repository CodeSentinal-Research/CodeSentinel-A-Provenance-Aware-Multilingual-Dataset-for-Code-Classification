
s,t=input().split()
m1={};m2={}
for a,b in zip(s,t):
    if m1.get(a,b)!=b or m2.get(b,a)!=a: print('No');exit()
    m1[a]=b;m2[b]=a
print('Yes' if len(s)==len(t) else 'No')
