# problem title : Find the Element that Appears Once in Sorted Array
# In a sorted paired array, the unique element breaks the expected even/odd pairing index.
n=int(input());a=list(map(int,input().split()));l,r=0,n-1
while l<r:
 m=(l+r)//2
 if m%2:m-=1
 if a[m]==a[m+1]:l=m+2
 else:r=m
print(a[l])
