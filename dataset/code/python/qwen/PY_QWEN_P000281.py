s = input().strip()
t = input().strip()
need = {}
for c in t: need[c] = need.get(c, 0) + 1
missing = len(t)
left = 0
min_len = float('inf')
min_start = 0
for right, c in enumerate(s):
    if c in need:
        if need[c] > 0:
            missing -= 1
        need[c] -= 1
    while missing == 0:
        if right - left + 1 < min_len:
            min_len = right - left + 1
            min_start = left
        if s[left] in need:
            need[s[left]] += 1
            if need[s[left]] > 0:
                missing += 1
        left += 1
print(s[min_start:min_start+min_len] if min_len != float('inf') else "")
