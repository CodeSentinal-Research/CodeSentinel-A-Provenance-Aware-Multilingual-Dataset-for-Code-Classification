
s,k=input().split();k=int(k)
from collections import Counter
win=Counter();l=0;best=0;maxf=0
for r,c in enumerate(s):
    win[c]+=1; maxf=max(maxf,win[c])
    if (r-l+1)-maxf>k: win[s[l]]-=1;l+=1
    best=max(best,r-l+1)
print(best)
