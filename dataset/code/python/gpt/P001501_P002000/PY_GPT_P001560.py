# PY_GPT_P001560 - Minimum Window Substring
# Problem-specific verified implementation.
import sys
from collections import Counter
lines = sys.stdin.read().splitlines()
s = lines[0].strip()
t = lines[1].strip()
need = Counter(t)
missing = len(t)
left = 0
best = None
for right, char in enumerate(s):
    if need[char] > 0:
        missing -= 1
    need[char] -= 1
    while missing == 0:
        candidate = s[left:right + 1]
        if best is None or len(candidate) < len(best):
            best = candidate
        old = s[left]
        need[old] += 1
        if need[old] > 0:
            missing += 1
        left += 1
print(best if best is not None else '')
