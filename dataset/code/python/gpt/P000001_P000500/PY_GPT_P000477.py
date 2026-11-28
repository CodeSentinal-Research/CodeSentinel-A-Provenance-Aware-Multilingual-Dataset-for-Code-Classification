# problem title : Find Pivot Index in Rotated Array
# The pivot is the index where the rotated sequence changes from a larger value to a smaller one.
n=int(input());a=list(map(int,input().split()));
for i in range(n):
 if a[i]>a[(i+1)%n]:print((i+1)%n);break
else:print(0)
