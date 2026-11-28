# PY_GPT_P001537 - Find All Anagrams in a String
# Problem-specific verified implementation.
s = input().strip()
p = input().strip()
from collections import Counter
if len(p) > len(s):
    print()
else:
    need = Counter(p)
    window = Counter(s[:len(p)])
    out = []
    if window == need:
        out.append(0)
    for r in range(len(p), len(s)):
        window[s[r]] += 1
        old = s[r - len(p)]
        window[old] -= 1
        if not window[old]:
            del window[old]
        if window == need:
            out.append(r - len(p) + 1)
    print(*out)
