# problem title : Product of Array Except Self
# Prefix and suffix products avoid division and handle zeroes naturally.
n = int(input()); a = list(map(int, input().split()))[:n]
result = [1] * n
prefix = 1
for i, x in enumerate(a):
    result[i] = prefix; prefix *= x
suffix = 1
for i in range(n - 1, -1, -1):
    result[i] *= suffix; suffix *= a[i]
print(*result)
