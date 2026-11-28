
text,pat=input().split();n,m=len(text),len(pat)
from collections import Counter
need=Counter(pat);win=Counter();res=[]
for r in range(n):
    win[text[r]]+=1
    if r>=m: win[text[r-m]]-=1;if not win[text[r-m]]:del win[text[r-m]]
    if win==need: res.append(r-m+1)
print(*res)
