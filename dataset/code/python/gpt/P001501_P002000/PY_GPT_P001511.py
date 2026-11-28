# PY_GPT_P001511 - Max Consecutive Answers
# Problem-specific verified implementation.
s = input().strip()
k = int(input())
left = t = f = best = 0
for right, ch in enumerate(s):
    t += ch == 'T'
    f += ch == 'F'
    while min(t, f) > k:
        t -= s[left] == 'T'
        f -= s[left] == 'F'
        left += 1
    best = max(best, right - left + 1)
print(best)
