# PY_GPT_P001576 - Count Windows Containing Zero
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
zeros = sum((x == 0 for x in a[:k]))
answer = int(zeros > 0)
for r in range(k, n):
    zeros += (a[r] == 0) - (a[r - k] == 0)
    answer += zeros > 0
print(answer)
