# problem title : Longest Common Substring
# DP stores the length of the common substring ending at each pair of positions.
a=input(); b=input(); prev=[0]*(len(b)+1); best=0; end=0
for i,x in enumerate(a,1):
    cur=[0]*(len(b)+1)
    for j,y in enumerate(b,1):
        if x==y: cur[j]=prev[j-1]+1; best=max(best,cur[j]); end=i
    prev=cur
print(a[end-best:end])
