# PY_GPT_P001507 - Longest Turbulent Subarray
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
if n <= 1:
    print(n)
else:
    current = best = 1
    for i in range(1, n):
        if a[i] == a[i - 1]:
            current = 1
        elif i == 1 or (a[i] > a[i - 1]) != (a[i - 1] > a[i - 2]):
            current += 1
        else:
            current = 2
        best = max(best, current)
    print(best)
