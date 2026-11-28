# PY_GPT_P001589 - Longest Well-Performing Interval
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
balance = 0
first = {}
best = 0
for i, hours in enumerate(a):
    balance += 1 if hours > 8 else -1
    if balance > 0:
        best = i + 1
    elif balance - 1 in first:
        best = max(best, i - first[balance - 1])
    first.setdefault(balance, i)
print(best)
