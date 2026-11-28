# PY_GPT_P001584 - Longest Substring With At Most K Vowels
# Problem-specific verified implementation.
s = input().strip()
k = int(input())
vowels = set('aeiouAEIOU')
left = count = best = 0
for right, ch in enumerate(s):
    count += ch in vowels
    while count > k:
        count -= s[left] in vowels
        left += 1
    best = max(best, right - left + 1)
print(best)
