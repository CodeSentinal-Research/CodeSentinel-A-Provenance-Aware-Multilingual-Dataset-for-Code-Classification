n = int(input())
arr = list(map(int, input().split()))
l, r = 0, n - 1
max_area = 0
while l < r:
    area = (r - l) * min(arr[l], arr[r])
    max_area = max(max_area, area)
    if arr[l] < arr[r]:
        l += 1
    else:
        r -= 1
print(max_area)
