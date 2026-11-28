# PY_GPT_P001533 - Longest Substring With Exactly K Distinct Characters
# Problem-specific verified implementation.
s = input().strip()
k = int(input())
freq = {}
left = 0
best = -1
for right, ch in enumerate(s):
    freq[ch] = freq.get(ch, 0) + 1
    while len(freq) > k:
        old = s[left]
        freq[old] -= 1
        if freq[old] == 0:
            del freq[old]
        left += 1
    if len(freq) == k:
        best = max(best, right - left + 1)
print(best)
