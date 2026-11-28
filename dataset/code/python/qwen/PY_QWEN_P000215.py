n, k = map(int, input().split())
arr = list(map(int, input().split()))
curr = sum(arr[:k])
max_sum = curr
for i in range(k, n):
    curr += arr[i] - arr[i - k]
    max_sum = max(max_sum, curr)
print(max_sum / k)
