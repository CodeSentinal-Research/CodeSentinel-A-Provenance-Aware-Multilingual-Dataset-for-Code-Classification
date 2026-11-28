n, k = map(int, input().split())
arr = list(map(int, input().split()))
curr = sum(arr[:k])
min_sum = curr
for i in range(k, n):
    curr += arr[i] - arr[i - k]
    min_sum = min(min_sum, curr)
print(min_sum)
