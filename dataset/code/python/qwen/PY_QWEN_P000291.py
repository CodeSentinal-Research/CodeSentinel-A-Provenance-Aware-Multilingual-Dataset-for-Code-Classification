s1 = input().strip()
s2 = input().strip()
need = {}
for c in s1: need[c] = need.get(c, 0) + 1
missing = len(s1)
left = 0
for right, c in enumerate(s2):
    if c in need:
        if need[c] > 0: missing -= 1
        need[c] -= 1
    if right - left + 1 == len(s1):
        if missing == 0:
            print("Yes")
            break
        if s2[left] in need:
            need[s2[left]] += 1
            if need[s2[left]] > 0: missing += 1
        left += 1
else:
    print("No")
