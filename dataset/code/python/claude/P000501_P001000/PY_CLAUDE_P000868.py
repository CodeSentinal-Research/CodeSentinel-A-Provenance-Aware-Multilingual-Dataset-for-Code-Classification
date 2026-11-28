
n=int(input());a=list(map(int,input().split()))
ans=0
for bit in range(32):
    ones=sum(1 for v in a if (v>>bit)&1)
    ans+=ones*(n-ones)
print(ans)
