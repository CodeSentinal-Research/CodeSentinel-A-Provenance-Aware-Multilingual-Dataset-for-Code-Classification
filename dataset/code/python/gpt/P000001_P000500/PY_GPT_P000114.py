# problem title : Rotate Array Left by K Positions
# Slice at K to rotate the sorted sequence left.
n, k = map(int, input().split()); a = list(map(int, input().split()))[:n]
k %= n
print(*(a[k:] + a[:k]))
