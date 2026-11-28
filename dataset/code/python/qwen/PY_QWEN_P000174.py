n = int(input())
arr = list(map(int, input().split()))
arr.sort()
min_diff = float('inf')
for i in range(1, n):
    min_diff = min(min_diff, arr[i] - arr[i-1])
print(min_diff)
