# problem title : Find All Anagrams in a String
# Compare character counts in each fixed-size window with the pattern counts.
from collections import Counter
text=input(); pat=input(); need=Counter(pat); cur=Counter(); out=[]; m=len(pat)
for i,ch in enumerate(text):
    cur[ch]+=1
    if i>=m: cur[text[i-m]]-=1
    if i>=m-1 and cur==need: out.append(i-m+1)
print(*out)
