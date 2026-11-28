
n=int(input());rem=list(map(int,input().split()));mod=list(map(int,input().split()))
x=0;M=1
for m in mod: M*=m
for r,m in zip(rem,mod):
    Mi=M//m
    x+=r*Mi*pow(Mi,m-2,m)
print(x%M)
