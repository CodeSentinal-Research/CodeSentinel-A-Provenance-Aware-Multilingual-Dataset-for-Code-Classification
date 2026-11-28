# problem title : Wave Array
# Sort first, then swap each adjacent pair to create the required wave inequalities.
n = int(input()); a = sorted(map(int, input().split()))[:n]
for i in range(0, n - 1, 2):
    a[i], a[i + 1] = a[i + 1], a[i]
print(*a)
