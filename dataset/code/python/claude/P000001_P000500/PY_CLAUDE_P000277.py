
s=input();seen={};l=r=0;best=0
for r,c in enumerate(s):
    if c in seen and seen[c]>=l: l=seen[c]+1
    seen[c]=r; best=max(best,r-l+1)
print(best)
