# PY_GPT_P001557 - Longest Repeating Character Replacement
# Problem-specific verified implementation.
s = input().strip()
k = int(input())
count = {}
left = best = common = 0
for right, ch in enumerate(s):
    count[ch] = count.get(ch, 0) + 1
    common = max(common, count[ch])
    while right - left + 1 - common > k:
        count[s[left]] -= 1
        left += 1
    best = max(best, right - left + 1)
print(best)
