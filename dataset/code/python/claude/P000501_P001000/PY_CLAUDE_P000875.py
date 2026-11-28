
a,b,c=int(input()),int(input()),int(input())
ans=0
for i in range(32):
    ba,bb,bc=(a>>i)&1,(b>>i)&1,(c>>i)&1
    if bc==0: ans+=ba+bb
    else: ans+=0 if ba|bb else 1
print(ans)
