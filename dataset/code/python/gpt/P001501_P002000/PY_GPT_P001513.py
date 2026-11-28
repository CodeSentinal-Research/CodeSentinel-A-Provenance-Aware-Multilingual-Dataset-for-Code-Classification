# PY_GPT_P001513 - Count Complete Subarrays
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
need = len(set(a))
count = {}
left = answer = 0
for right, x in enumerate(a):
    count[x] = count.get(x, 0) + 1
    while len(count) == need:
        answer += n - right
        y = a[left]
        count[y] -= 1
        if count[y] == 0:
            del count[y]
        left += 1
print(answer)
