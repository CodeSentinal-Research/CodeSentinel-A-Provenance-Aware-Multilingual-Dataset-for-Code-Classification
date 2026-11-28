# PY_GPT_P001538 - Permutation in String
# Problem-specific verified implementation.
s1 = input().strip()
s2 = input().strip()
from collections import Counter
found = False
if len(s1) <= len(s2):
    need = Counter(s1)
    window = Counter(s2[:len(s1)])
    found = window == need
    for r in range(len(s1), len(s2)):
        window[s2[r]] += 1
        old = s2[r - len(s1)]
        window[old] -= 1
        if not window[old]:
            del window[old]
        found = found or window == need
print('YES' if found else 'NO')
