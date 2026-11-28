s1 = input().strip()
s2 = input().strip()
i = 0
for c in s1:
    if i < len(s2) and c == s2[i]:
        i += 1
print("Yes" if i == len(s2) else "No")
