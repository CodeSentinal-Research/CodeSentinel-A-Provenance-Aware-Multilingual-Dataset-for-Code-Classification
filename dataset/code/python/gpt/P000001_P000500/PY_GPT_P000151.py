# problem title : Find Maximum Product of Two Elements
# The maximum product comes from the two largest positives or two most negative values.
n = int(input()); a = list(map(int, input().split()))[:n]
a.sort()
print(max(a[0] * a[1], a[-1] * a[-2]))
