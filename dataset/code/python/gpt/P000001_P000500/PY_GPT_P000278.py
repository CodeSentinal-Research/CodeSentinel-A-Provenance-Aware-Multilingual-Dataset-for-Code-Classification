# problem title : Longest Palindromic Substring
# Expand around every character and every gap to find the longest palindrome.
s=input(); best=''
def expand(l,r):
    while l>=0 and r<len(s) and s[l]==s[r]: l-=1; r+=1
    return s[l+1:r]
for i in range(len(s)):
    for a,b in ((i,i),(i,i+1)):
        cur=expand(a,b)
        if len(cur)>len(best): best=cur
print(best)
