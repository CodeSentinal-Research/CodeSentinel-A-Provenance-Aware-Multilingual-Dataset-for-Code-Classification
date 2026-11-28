import bisect
n, target = map(int, input().split())
arr = list(map(int, input().split()))
idx = bisect.bisect_right(arr, target) - 1
if idx >= 0 and arr[idx] == target:
    print(idx)
else:
    print(-1)
