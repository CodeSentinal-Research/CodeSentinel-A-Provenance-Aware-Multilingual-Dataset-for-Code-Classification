# PY_GPT_P001539 - Count Vowel Substrings of a String
# Problem-specific verified implementation.
import sys
s = sys.stdin.readline().strip()
vowels = set('aeiou')
answer = 0
for start in range(len(s)):
    present = set()
    for end in range(start, len(s)):
        if s[end] not in vowels:
            break
        present.add(s[end])
        if present:
            answer += 1
print(answer)
