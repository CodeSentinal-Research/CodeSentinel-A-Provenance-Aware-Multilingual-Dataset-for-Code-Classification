# PY_GPT_P001588 - Count Nice Subarrays
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
positions = [-1] + [i for i, x in enumerate(a) if x % 2]
answer = 0
for i in range(1, len(positions)):
    right = positions[i + 1] - positions[i] if i + 1 < len(positions) else n - positions[i]
    answer += (positions[i] - positions[i - 1]) * right
print(answer)
