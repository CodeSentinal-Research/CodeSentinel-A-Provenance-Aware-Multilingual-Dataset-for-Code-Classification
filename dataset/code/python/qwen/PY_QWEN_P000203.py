n, k = map(int, input().split())
arr = list(map(int, input().split()))
for x in arr:
    arr[x % k] += k
max_val = -1
res = -1
for i in range(k):
    if arr[i] > max_val:
        max_val = arr[i]
        res = i
print(res)
