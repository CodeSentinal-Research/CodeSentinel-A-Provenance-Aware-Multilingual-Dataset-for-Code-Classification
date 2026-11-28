# problem title : Sort Array in Wave Form
# Sort first, then swap each adjacent pair to create a <= >= <= wave pattern.
n=int(input()); a=list(map(int,input().split())); a.sort()
for i in range(0,n-1,2): a[i],a[i+1]=a[i+1],a[i]
print(*a)
