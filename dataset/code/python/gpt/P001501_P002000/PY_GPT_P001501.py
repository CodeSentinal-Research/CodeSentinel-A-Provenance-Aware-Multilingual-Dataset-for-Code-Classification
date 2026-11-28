# PY_GPT_P001501 - Maximize Distance to Closest Person
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
occupied = [i for i, x in enumerate(a) if x == 1]
answer = max(occupied[0], n - 1 - occupied[-1]) if occupied else 0
for x, y in zip(occupied, occupied[1:]):
    answer = max(answer, (y - x) // 2)
print(answer)
