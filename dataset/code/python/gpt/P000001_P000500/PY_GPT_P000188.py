# problem title : Subarray with Given Sum (Positive Numbers)
# With positive numbers, a sliding window finds a target sum in linear time.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
left = total = 0; answer = -1
for right, value in enumerate(a):
    total += value
    while total > target and left <= right:
        total -= a[left]; left += 1
    if total == target:
        answer = (left + 1, right + 1); break
if answer == -1: print(-1)
else: print(*answer)
