# PY_GPT_P001572 - Count Windows With Even Sum
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
even = sum((x % 2 == 0 for x in a[:k]))
answer = int(even == k)
for r in range(k, n):
    even += (a[r] % 2 == 0) - (a[r - k] % 2 == 0)
    answer += even % 2 == 0
print(answer)
