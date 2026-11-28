n = int(input())
arr = list(map(int, input().split()))
max_prod = arr[0]
min_prod = arr[0]
res = arr[0]
for i in range(1, n):
    if arr[i] < 0:
        max_prod, min_prod = min_prod, max_prod
    max_prod = max(arr[i], max_prod * arr[i])
    min_prod = min(arr[i], min_prod * arr[i])
    res = min(res, min_prod)
print(res)
