import bisect
n, target = map(int, input().split())
arr = list(map(int, input().split()))
idx = bisect.bisect_left(arr, target)
if idx < n and arr[idx] == target:
    print(idx)
else:
    print(-1)
