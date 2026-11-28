# PY_GPT_P001530 - Maximum Erasure Value
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
seen = set()
left = total = best = 0
for right, x in enumerate(a):
    while x in seen:
        seen.remove(a[left])
        total -= a[left]
        left += 1
    seen.add(x)
    total += x
    best = max(best, total)
print(best)
