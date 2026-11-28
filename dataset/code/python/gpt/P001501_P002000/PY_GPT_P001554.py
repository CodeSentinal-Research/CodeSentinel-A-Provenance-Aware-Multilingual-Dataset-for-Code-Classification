# PY_GPT_P001554 - Longest Substring Without Repeating Characters
# Problem-specific verified implementation.
s = input().strip()
last = {}
left = best = 0
for right, ch in enumerate(s):
    if ch in last:
        left = max(left, last[ch] + 1)
    last[ch] = right
    best = max(best, right - left + 1)
print(best)
