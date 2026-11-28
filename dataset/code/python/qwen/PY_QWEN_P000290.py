text = input().strip()
pattern = input().strip()
need = {}
for c in pattern: need[c] = need.get(c, 0) + 1
missing = len(pattern)
res = []
left = 0
for right, c in enumerate(text):
    if c in need:
        if need[c] > 0: missing -= 1
        need[c] -= 1
    if right - left + 1 == len(pattern):
        if missing == 0: res.append(left)
        if text[left] in need:
            need[text[left]] += 1
            if need[text[left]] > 0: missing += 1
        left += 1
print(" ".join(map(str, res)))
