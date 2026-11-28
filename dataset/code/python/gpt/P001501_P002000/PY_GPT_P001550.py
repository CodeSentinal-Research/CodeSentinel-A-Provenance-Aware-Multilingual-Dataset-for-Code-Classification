# PY_GPT_P001550 - Sum of Absolute Differences in Each Window
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
out = []
for left in range(n - k + 1):
    w = a[left:left + k]
    total = sum(w)
    out.append(sum((abs(x - total / k) for x in w)))
print(*out)
