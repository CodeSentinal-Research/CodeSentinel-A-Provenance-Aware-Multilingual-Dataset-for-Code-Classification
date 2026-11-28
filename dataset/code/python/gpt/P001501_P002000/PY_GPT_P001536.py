# PY_GPT_P001536 - Minimum Window Substring
# Problem-specific verified implementation.
s = input().strip()
t = input().strip()
from collections import Counter
need = Counter(t)
have = Counter()
left = formed = 0
best = None
for right, ch in enumerate(s):
    have[ch] += 1
    formed += ch in need and have[ch] == need[ch]
    while formed == len(need):
        candidate = s[left:right + 1]
        if best is None or len(candidate) < len(best):
            best = candidate
        drop = s[left]
        have[drop] -= 1
        formed -= drop in need and have[drop] < need[drop]
        left += 1
print(best or '')
