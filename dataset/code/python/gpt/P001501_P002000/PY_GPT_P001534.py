# PY_GPT_P001534 - Longest Substring With At Most Two Distinct Characters
# Problem-specific verified implementation.
s = input().strip()
freq = {}
left = best = 0
for right, ch in enumerate(s):
    freq[ch] = freq.get(ch, 0) + 1
    while len(freq) > 2:
        old = s[left]
        freq[old] -= 1
        if freq[old] == 0:
            del freq[old]
        left += 1
    best = max(best, right - left + 1)
print(best)
