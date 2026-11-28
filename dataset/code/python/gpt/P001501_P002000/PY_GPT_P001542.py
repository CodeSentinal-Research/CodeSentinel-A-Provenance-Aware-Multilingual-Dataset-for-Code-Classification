# PY_GPT_P001542 - Average of Every Window
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
current = sum(a[:k])
out = [current / k]
for r in range(k, n):
    current += a[r] - a[r - k]
    out.append(current / k)
print(*out)
