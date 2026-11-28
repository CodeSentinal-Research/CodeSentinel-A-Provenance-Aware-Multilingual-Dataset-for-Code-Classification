# PY_GPT_P001561 - Substring With Concatenation of All Words
# Problem-specific verified implementation.
s = input().strip()
m = int(input())
words = input().split()
from collections import Counter
if not words or len(words[0]) == 0:
    print(-1)
else:
    size = len(words[0])
    need = Counter(words)
    out = []
    for offset in range(size):
        left = offset
        used = Counter()
        count = 0
        for right in range(offset, len(s) - size + 1, size):
            word = s[right:right + size]
            if word not in need:
                used.clear()
                count = 0
                left = right + size
                continue
            used[word] += 1
            count += 1
            while used[word] > need[word]:
                old = s[left:left + size]
                used[old] -= 1
                left += size
                count -= 1
            if count == m:
                out.append(left)
                old = s[left:left + size]
                used[old] -= 1
                left += size
                count -= 1
    out.sort()
    print(*out) if out else print(-1)
