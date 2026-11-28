# problem title : Valid Palindrome II
# At most one mismatch is allowed; after finding it, skip either side once.
s=input()
def pal(l,r):
    while l<r:
        if s[l]!=s[r]: return False
        l+=1;r-=1
    return True
i,j=0,len(s)-1
while i<j and s[i]==s[j]:i+=1;j-=1
print("Yes" if i>=j or pal(i+1,j) or pal(i,j-1) else "No")
