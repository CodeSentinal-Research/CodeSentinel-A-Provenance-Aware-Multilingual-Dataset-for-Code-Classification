import bisect
n, target = map(int, input().split())
arr = list(map(int, input().split()))
l = bisect.bisect_left(arr, target)
r = bisect.bisect_right(arr, target)
if l < n and arr[l] == target:
    print(r - l)
else:
    print(0)
