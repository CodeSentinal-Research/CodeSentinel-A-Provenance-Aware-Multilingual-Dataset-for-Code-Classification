n = int(input())
arr = list(map(int, input().split()))
for x in arr:
    idx = abs(x) - 1
    if arr[idx] > 0:
        arr[idx] = -arr[idx]
res = []
for i in range(n):
    if arr[i] > 0:
        res.append(i + 1)
print(" ".join(map(str, res)))
