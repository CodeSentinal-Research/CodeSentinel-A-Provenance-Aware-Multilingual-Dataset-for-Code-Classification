# PY_GPT_P001515 - Count Alternating Subarrays
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
length = answer = 0
for i, x in enumerate(a):
    length = length + 1 if i and x != a[i - 1] else 1
    answer += length
print(answer)
