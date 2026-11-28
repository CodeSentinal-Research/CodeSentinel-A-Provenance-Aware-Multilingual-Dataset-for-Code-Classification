# PY_GPT_P001577 - Count Strictly Increasing Windows
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
answer = 0
for left in range(n - k + 1):
    answer += all((a[i] < a[i + 1] for i in range(left, left + k - 1)))
print(answer)
