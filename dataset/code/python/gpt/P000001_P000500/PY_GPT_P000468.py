# problem title : Find Kth Element of Two Sorted Arrays
# Merge only until the K-th position so unnecessary values are not processed.
m,n,k=map(int,input().split());a=list(map(int,input().split()));b=list(map(int,input().split()));i=j=0;v=None
for _ in range(k):
 if j>=n or (i<m and a[i]<=b[j]):v=a[i];i+=1
 else:v=b[j];j+=1
print(v)
