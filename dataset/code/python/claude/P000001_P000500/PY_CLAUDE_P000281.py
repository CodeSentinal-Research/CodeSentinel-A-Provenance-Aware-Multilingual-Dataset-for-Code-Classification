
s,t=input().split()
from collections import Counter
need=Counter(t);missing=len(t);l=0;best=''
win={}
for r,c in enumerate(s):
    win[c]=win.get(c,0)+1
    if need.get(c,0)>0 and win[c]<=need[c]: missing-=1
    while missing==0:
        if not best or r-l+1<len(best): best=s[l:r+1]
        lc=s[l];win[lc]-=1
        if need.get(lc,0)>0 and win[lc]<need[lc]: missing+=1
        l+=1
print(best)
