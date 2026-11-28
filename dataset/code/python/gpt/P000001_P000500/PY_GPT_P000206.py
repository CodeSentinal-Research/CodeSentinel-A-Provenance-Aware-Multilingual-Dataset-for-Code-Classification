# problem title : Find Median of Two Sorted Arrays of Different Sizes
# Merging is simple and safe for the stated input sizes.
m,n=map(int,input().split()); a=list(map(int,input().split())); b=list(map(int,input().split()))
c=sorted(a+b); z=len(c)
print(c[z//2] if z%2 else (c[z//2-1]+c[z//2])/2)
