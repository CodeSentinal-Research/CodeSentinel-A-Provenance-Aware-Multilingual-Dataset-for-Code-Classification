n, target = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
for i in range(n - 2):
    seen = {}
    for j in range(i + 1, n):
        need = target - arr[i] - arr[j]
        if need in seen:
            ans += seen[need]
        seen[arr[j]] = seen.get(arr[j], 0) + 1
print(ans)
