# PY_GPT_P001578 - Count Windows With All Distinct Elements
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
answer = 0
for left in range(n - k + 1):
    answer += len(set(a[left:left + k])) == k
print(answer)
