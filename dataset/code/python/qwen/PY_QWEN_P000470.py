n, target = map(int, input().split())
arr = list(map(int, input().split()))
import bisect
idx = bisect.bisect_left(arr, target)
candidates = []
if idx < n: candidates.append(arr[idx])
if idx > 0: candidates.append(arr[idx-1])
print(min(candidates, key=lambda x: abs(x - target)))
