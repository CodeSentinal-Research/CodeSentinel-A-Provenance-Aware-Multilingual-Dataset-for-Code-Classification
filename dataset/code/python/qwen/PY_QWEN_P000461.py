import bisect
n = int(input())
arr = list(map(int, input().split()))
idx = bisect.bisect_left(arr, 1)
if idx < n:
    print(idx)
else:
    print(-1)
