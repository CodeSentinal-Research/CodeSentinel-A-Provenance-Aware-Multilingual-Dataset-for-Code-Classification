# PY_GPT_P001564 - Sliding Window Median
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
import bisect
w = sorted(a[:k])
out = []
for i in range(k - 1, n):
    if i >= k:
        old = a[i - k]
        w.pop(bisect.bisect_left(w, old))
        bisect.insort(w, a[i])
    if k % 2:
        out.append(w[k // 2])
    else:
        out.append((w[k // 2 - 1] + w[k // 2]) / 2)
print(*out)
