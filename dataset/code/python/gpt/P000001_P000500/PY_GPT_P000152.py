# problem title : Find Minimum Product of Two Elements
# The minimum product must use the smallest pair among opposite extremes.
n = int(input()); a = sorted(map(int, input().split()))[:n]
print(min(a[0] * a[-1], a[0] * a[1], a[-2] * a[-1]))
