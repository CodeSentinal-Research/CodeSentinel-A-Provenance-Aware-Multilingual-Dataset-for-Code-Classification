# problem title : Maximum Size Rectangle of All 1s
# Treat every matrix row as a histogram and compute the largest rectangle in each histogram.
def hist(h):
    st=[]; best=0
    for i,x in enumerate(h+[0]):
        while st and h[st[-1]]>x:
            k=st.pop(); left=st[-1]+1 if st else 0; best=max(best,h[k]*(i-left))
        st.append(i)
    return best
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]; h=[0]*c; ans=0
for row in a:
    for j,v in enumerate(row): h[j]=h[j]+1 if v else 0
    ans=max(ans,hist(h))
print(ans)
