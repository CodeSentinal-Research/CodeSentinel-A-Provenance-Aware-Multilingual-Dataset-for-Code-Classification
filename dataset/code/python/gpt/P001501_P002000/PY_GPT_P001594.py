# PY_GPT_P001594 - Prefix Sum Array
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
running = 0
out = []
for x in a:
    running += x
    out.append(running)
print(*out)
