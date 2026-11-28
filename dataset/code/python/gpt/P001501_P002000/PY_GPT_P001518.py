# PY_GPT_P001518 - Successful Pairs of Spells and Potions
# Problem-specific verified implementation.
n, m, success = map(int, input().split())
spells = list(map(int, input().split()))
potions = sorted(map(int, input().split()))
from bisect import bisect_left
answer = []
for spell in spells:
    need = (success + spell - 1) // spell
    answer.append(m - bisect_left(potions, need))
print(*answer)
