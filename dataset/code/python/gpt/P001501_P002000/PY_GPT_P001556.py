# PY_GPT_P001556 - Count Anagram Occurrences
# Problem-specific verified implementation.
text = input().strip()
pattern = input().strip()
from collections import Counter
if len(pattern) > len(text):
    print(0)
else:
    need = Counter(pattern)
    window = Counter(text[:len(pattern)])
    answer = int(window == need)
    for r in range(len(pattern), len(text)):
        window[text[r]] += 1
        old = text[r - len(pattern)]
        window[old] -= 1
        if not window[old]:
            del window[old]
        answer += window == need
    print(answer)
