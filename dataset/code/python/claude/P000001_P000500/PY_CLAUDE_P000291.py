
s1,s2=input().split();m=len(s1)
from collections import Counter
if m>len(s2): print('No');exit()
need=Counter(s1);win=Counter(s2[:m])
if win==need: print('Yes');exit()
for i in range(m,len(s2)):
    win[s2[i]]+=1;win[s2[i-m]]-=1
    if not win[s2[i-m]]: del win[s2[i-m]]
    if win==need: print('Yes');exit()
print('No')
