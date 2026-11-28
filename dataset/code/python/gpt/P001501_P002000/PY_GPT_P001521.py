# PY_GPT_P001521 - Max Chunks to Make Sorted II
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
suffix = [0] * n
suffix[-1] = a[-1]
for i in range(n - 2, -1, -1):
    suffix[i] = min(a[i], suffix[i + 1])
chunks = 0
left_max = float('-inf')
for i, x in enumerate(a):
    left_max = max(left_max, x)
    if i == n - 1 or left_max <= suffix[i + 1]:
        chunks += 1
print(chunks)
