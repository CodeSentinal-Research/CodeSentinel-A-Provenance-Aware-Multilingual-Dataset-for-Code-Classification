# PY_GPT_P001525 - Longest Continuous Subarray With Equal Number of Even and Odd Elements
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
first = {0: -1}
balance = best = 0
for i, x in enumerate(a):
    balance += 1 if x % 2 == 0 else -1
    if balance in first:
        best = max(best, i - first[balance])
    else:
        first[balance] = i
print(best)
