# PY_GPT_P001506 - Minimum Window Subsequence
# Problem-specific verified implementation.
s = input().strip()
t = input().strip()
best = ''
start = 0
while start < len(s):
    first = s.find(t[0], start) if t else -1
    if first < 0:
        break
    i = first
    j = 0
    while i < len(s) and j < len(t):
        if s[i] == t[j]:
            j += 1
        i += 1
    if j < len(t):
        break
    candidate = s[first:i]
    if not best or len(candidate) < len(best):
        best = candidate
    start = first + 1
print(best)
