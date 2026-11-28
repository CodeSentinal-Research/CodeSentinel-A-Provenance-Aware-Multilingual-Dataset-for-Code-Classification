# problem title : Longest Repeating Character Replacement
# Sliding window stays valid when replacements needed are at most K.
s=input(); k=int(input()); freq={}; left=best=mx=0
for right,ch in enumerate(s):
    freq[ch]=freq.get(ch,0)+1; mx=max(mx,freq[ch])
    while right-left+1-mx>k:
        freq[s[left]]-=1; left+=1
    best=max(best,right-left+1)
print(best)
