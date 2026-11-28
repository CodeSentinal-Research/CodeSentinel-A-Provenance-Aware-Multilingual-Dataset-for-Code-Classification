# PY_GPT_P001579 - Maximum Count of Negative Numbers in a Window
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
negative = sum((x < 0 for x in a[:k]))
best = negative
for r in range(k, n):
    negative += (a[r] < 0) - (a[r - k] < 0)
    best = max(best, negative)
print(best)
