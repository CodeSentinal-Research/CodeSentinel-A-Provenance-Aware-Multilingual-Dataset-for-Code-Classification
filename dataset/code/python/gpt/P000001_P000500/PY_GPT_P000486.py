# problem title : Largest Rectangle in Histogram
# Monotonic stack finds the nearest smaller boundary for every histogram bar.
h=list(map(int,input().split()));st=[];best=0
for i,x in enumerate(h+[0]):
 while st and h[st[-1]]>x:
  k=st.pop();left=st[-1]+1 if st else 0;best=max(best,h[k]*(i-left))
 st.append(i)
print(best)
