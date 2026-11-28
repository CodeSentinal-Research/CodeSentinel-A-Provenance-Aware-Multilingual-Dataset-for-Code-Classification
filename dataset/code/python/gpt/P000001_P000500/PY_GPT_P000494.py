# problem title : Daily Temperatures
# A decreasing stack stores indices whose next warmer day has not been found.
t=list(map(int,input().split()));st=[];ans=[0]*len(t)
for i,x in enumerate(t):
 while st and t[st[-1]]<x:
  j=st.pop();ans[j]=i-j
 st.append(i)
print(*ans)
