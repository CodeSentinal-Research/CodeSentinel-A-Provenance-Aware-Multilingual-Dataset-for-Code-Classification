# PY_GPT_P001592 - Earliest Prefix With Sum At Least X
# Problem-specific verified implementation.
n, x = map(int, input().split())
a = list(map(int, input().split()))
running = 0
answer = -1
for i, value in enumerate(a):
    running += value
    if running >= x:
        answer = i + 1
        break
print(answer)
