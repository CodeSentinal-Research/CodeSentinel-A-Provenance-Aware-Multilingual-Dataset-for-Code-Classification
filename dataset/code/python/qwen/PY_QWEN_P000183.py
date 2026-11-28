n, k = map(int, input().split())
arr = list(map(int, input().split()))
counts = {}
res = []
for i in range(n):
    counts[arr[i]] = counts.get(arr[i], 0) + 1
    if i >= k:
        counts[arr[i - k]] -= 1
        if counts[arr[i - k]] == 0:
            del counts[arr[i - k]]
    if i >= k - 1:
        res.append(len(counts))
print(" ".join(map(str, res)))
