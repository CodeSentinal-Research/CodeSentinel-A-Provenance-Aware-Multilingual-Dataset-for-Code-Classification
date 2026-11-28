# problem title : Minimum Product Subarray
# The minimum-product variant keeps the smallest and largest products.
n = int(input()); a = list(map(int, input().split()))[:n]
mx = mn = answer = a[0]
for x in a[1:]:
    if x < 0: mx, mn = mn, mx
    mx = max(x, mx * x); mn = min(x, mn * x); answer = min(answer, mn)
print(answer)
