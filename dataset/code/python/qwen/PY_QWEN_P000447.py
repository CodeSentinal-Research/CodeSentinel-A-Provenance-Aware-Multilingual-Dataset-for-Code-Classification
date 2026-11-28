import bisect
n, target = map(int, input().split())
arr = list(map(int, input().split()))
l = bisect.bisect_left(arr, target)
r = bisect.bisect_right(arr, target) - 1
if l < n and arr[l] == target:
    print(l, r)
else:
    print(-1, -1)
