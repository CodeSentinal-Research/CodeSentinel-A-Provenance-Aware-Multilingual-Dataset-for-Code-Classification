# PY_GPT_P001555 - Maximum Number of Vowels in a Substring of Length K
# Problem-specific verified implementation.
s = input().strip()
k = int(input())
vowels = set('aeiouAEIOU')
current = sum((c in vowels for c in s[:k]))
best = current
for r in range(k, len(s)):
    current += s[r] in vowels
    current -= s[r - k] in vowels
    best = max(best, current)
print(best)
