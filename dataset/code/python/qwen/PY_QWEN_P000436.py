import bisect
n, target = map(int, input().split())
arr = list(map(int, input().split()))
print(bisect.bisect_left(arr, target))
