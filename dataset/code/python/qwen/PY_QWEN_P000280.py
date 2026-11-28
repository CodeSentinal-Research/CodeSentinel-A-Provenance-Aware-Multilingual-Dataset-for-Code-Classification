s1 = input().strip()
s2 = input().strip()
if abs(len(s1) - len(s2)) > 1:
    print("No")
else:
    c1, c2 = {}, {}
    for c in s1: c1[c] = c1.get(c, 0) + 1
    for c in s2: c2[c] = c2.get(c, 0) + 1
    diff = 0
    for c in set(list(c1.keys()) + list(c2.keys())):
        diff += abs(c1.get(c, 0) - c2.get(c, 0))
    print("Yes" if diff <= 1 else "No")
