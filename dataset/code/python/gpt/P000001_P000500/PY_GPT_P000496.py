# problem title : Sum of Subarray Minimums
# Monotonic boundaries determine how many subarrays use each value as their minimum.
MOD=10**9+7;a=list(map(int,input().split()));n=len(a);left=[0]*n;right=[0]*n;st=[]
for i,x in enumerate(a):
 while st and a[st[-1]]>x:st.pop()
 left[i]=i-st[-1] if st else i+1;st.append(i)
st=[]
for i in range(n-1,-1,-1):
 while st and a[st[-1]]>=a[i]:st.pop()
 right[i]=st[-1]-i if st else n-i;st.append(i)
print(sum(a[i]*left[i]*right[i] for i in range(n))%MOD)
