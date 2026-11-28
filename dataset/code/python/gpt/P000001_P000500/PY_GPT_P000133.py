# problem title : Rearrange Array Alternately
# Alternate the smallest and largest remaining values of the sorted input.
n = int(input()); a = list(map(int, input().split()))[:n]
lo, hi = 0, n - 1
out = []
while lo <= hi:
    out.append(a[hi]); hi -= 1
    if lo <= hi:
        out.append(a[lo]); lo += 1
print(*out)
