# PY_GPT_P001508 - Fruit Into Baskets
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
count = {}
left = best = 0
for right, x in enumerate(a):
    count[x] = count.get(x, 0) + 1
    while len(count) > 2:
        y = a[left]
        count[y] -= 1
        if count[y] == 0:
            del count[y]
        left += 1
    best = max(best, right - left + 1)
print(best)
