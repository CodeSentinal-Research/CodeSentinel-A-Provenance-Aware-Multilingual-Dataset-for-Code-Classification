
n=int(input());a=list(map(int,input().split()))
s=sorted(a)
if a==s: print(0);exit()
l,r=0,n-1
while a[l]==s[l]: l+=1
while a[r]==s[r]: r-=1
print(r-l+1)
