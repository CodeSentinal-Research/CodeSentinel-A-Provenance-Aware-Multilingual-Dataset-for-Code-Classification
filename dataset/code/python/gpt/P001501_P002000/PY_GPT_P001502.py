# PY_GPT_P001502 - Minimum Swaps to Group All Ones Together
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
k = sum(a)
if k <= 1:
    print(0)
else:
    zeros = k - sum(a[:k])
    best = zeros
    for r in range(k, n):
        zeros += (a[r] == 0) - (a[r - k] == 0)
        best = min(best, zeros)
    print(best)
