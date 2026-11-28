
s=input();n=len(s);best=''
def expand(l,r):
    while l>=0 and r<n and s[l]==s[r]: l-=1;r+=1
    return s[l+1:r]
for i in range(n):
    for p in [expand(i,i),expand(i,i+1)]:
        if len(p)>len(best): best=p
print(best)
