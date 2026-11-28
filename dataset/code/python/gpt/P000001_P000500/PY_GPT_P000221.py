# problem title : Maximum Length Chain of Pairs
# Sort pairs by their second value and greedily extend the chain.
n=int(input()); pairs=[tuple(map(int,input().split())) for _ in range(n)]; pairs.sort(key=lambda x:x[1]); end=-10**18; ans=0
for s,f in pairs:
    if s>end: ans+=1; end=f
print(ans)
