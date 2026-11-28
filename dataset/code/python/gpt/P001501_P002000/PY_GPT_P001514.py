# PY_GPT_P001514 - Longest Semi-Repetitive Substring
# Problem-specific verified implementation.
s = input().strip()
left = repeats = best = 0
for right in range(len(s)):
    if right and s[right] == s[right - 1]:
        repeats += 1
    while repeats > 1:
        if left < right and s[left] == s[left + 1]:
            repeats -= 1
        left += 1
    best = max(best, right - left + 1)
print(best)
