n = int(input())
arr = list(map(int, input().split()))
l, r = 0, n - 1
while l < r:
    mid = (l + r) // 2
    if arr[mid] > arr[mid+1]:
        r = mid
    else:
        l = mid + 1
print(l)
