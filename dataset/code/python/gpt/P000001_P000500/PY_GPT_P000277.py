# problem title : Longest Substring Without Repeating Characters
# Sliding window maintains a substring with unique characters.
s=input(); last={}; left=best=0
for right,ch in enumerate(s):
    if ch in last and last[ch]>=left:left=last[ch]+1
    last[ch]=right; best=max(best,right-left+1)
print(best)
