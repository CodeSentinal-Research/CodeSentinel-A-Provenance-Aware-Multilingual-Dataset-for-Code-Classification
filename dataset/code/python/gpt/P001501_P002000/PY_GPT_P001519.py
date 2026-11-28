# PY_GPT_P001519 - Longest Continuous Increasing Subsequence
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
best = current = 0
for i, x in enumerate(a):
    current = current + 1 if i == 0 or x > a[i - 1] else 1
    best = max(best, current)
print(best)
