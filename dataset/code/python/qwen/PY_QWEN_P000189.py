n = int(input())
arr = list(map(int, input().split()))
max_kadane = float('-inf')
curr = 0
for x in arr:
    curr = max(x, curr + x)
    max_kadane = max(max_kadane, curr)
total = sum(arr)
min_kadane = float('inf')
curr = 0
for x in arr:
    curr = min(x, curr + x)
    min_kadane = min(min_kadane, curr)
if total == min_kadane:
    print(max_kadane)
else:
    print(max(max_kadane, total - min_kadane))
