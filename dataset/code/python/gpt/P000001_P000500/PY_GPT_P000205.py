# problem title : Find Median of Two Sorted Arrays of Same Size
# Merge the two sorted arrays conceptually and read the middle two values.
n=int(input()); a=list(map(int,input().split())); b=list(map(int,input().split()))
c=sorted(a+b); m=2*n
print((c[m//2-1]+c[m//2])/2)
