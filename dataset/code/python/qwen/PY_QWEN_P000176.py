n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
min_diff = float('inf')
for i in range(n - k + 1):
    min_diff = min(min_diff, arr[i + k - 1] - arr[i])
print(min_diff)
