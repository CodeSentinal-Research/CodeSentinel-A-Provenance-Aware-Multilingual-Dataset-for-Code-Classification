# problem title : Minimum Window Substring
# Sliding window expands until it covers T, then shrinks to the smallest valid window.
from collections import Counter
s=input(); t=input(); need=Counter(t); have=Counter(); left=0; formed=0; best=(10**9,0,0)
for right,ch in enumerate(s):
    have[ch]+=1
    if have[ch]==need[ch]: formed+=1
    while formed==len(need):
        if right-left+1<best[0]: best=(right-left+1,left,right+1)
        x=s[left]; have[x]-=1
        if have[x]<need[x]: formed-=1
        left+=1
print(s[best[1]:best[2]] if best[0]<10**9 else '')
