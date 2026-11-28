# problem title : Find K Closest Elements
# Use a window in the sorted array and choose the K values closest to target.
n, k, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
left, right = 0, n - k
while left < right:
    if abs(target - a[left]) > abs(a[right + k - 1] - target): left += 1
    else: right -= 1
print(*a[left:left + k])
