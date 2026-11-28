# problem title : Edit Distance
# Edit distance uses insert, delete, and replace transitions between prefixes.
a=input(); b=input(); dp=list(range(len(b)+1))
for i,x in enumerate(a,1):
    nd=[i]
    for j,y in enumerate(b,1): nd.append(dp[j-1] if x==y else 1+min(dp[j],nd[-1],dp[j-1]))
    dp=nd
print(dp[-1])
