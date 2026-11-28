n, target = map(int, input().split())
arr = list(map(int, input().split()))
peak = 0
for i in range(1, n):
    if arr[i] > arr[i-1]:
        peak = i
    else:
        break
import bisect
idx = bisect.bisect_left(arr[:peak+1], target)
if idx <= peak and arr[idx] == target:
    print(idx)
else:
    idx2 = bisect.bisect_left(arr[peak+1:][::-1], target)
    real_idx = n - 1 - idx2
    if real_idx > peak and arr[real_idx] == target:
        print(real_idx)
    else:
        print(-1)
