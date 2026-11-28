# problem title : Shortest Distance to a Character
# Record nearest positions from the left and right, taking the smaller distance.
s=input(); c=input().strip()[0]; n=len(s); ans=[n]*n; last=-10**9
for i,ch in enumerate(s):
    if ch==c:last=i
    ans[i]=i-last
last=10**9
for i in range(n-1,-1,-1):
    if s[i]==c:last=i
    ans[i]=min(ans[i],last-i)
print(*ans)
