# PY_GPT_P001540 - Count Complete Vowel Substrings
# Problem-specific verified implementation.
import sys
s = sys.stdin.readline().strip()
vowels = set('aeiou')
answer = 0
for start in range(len(s)):
    seen = set()
    for end in range(start, len(s)):
        char = s[end]
        if char not in vowels:
            break
        seen.add(char)
        if len(seen) == 5:
            answer += 1
print(answer)
