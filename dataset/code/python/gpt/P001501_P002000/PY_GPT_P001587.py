# PY_GPT_P001587 - Number of Substrings Containing All Three Characters
# Problem-specific verified implementation.
s = input().strip()
last = [-1, -1, -1]
answer = 0
for i, ch in enumerate(s):
    last[ord(ch) - 97] = i
    if min(last) >= 0:
        answer += min(last) + 1
print(answer)
