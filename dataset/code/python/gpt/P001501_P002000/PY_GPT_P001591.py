# PY_GPT_P001591 - Range Sum Query
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
q = int(input())
prefix = [0]
for x in a:
    prefix.append(prefix[-1] + x)
for _ in range(q):
    l, r = map(int, input().split())
    print(prefix[r + 1] - prefix[l])
