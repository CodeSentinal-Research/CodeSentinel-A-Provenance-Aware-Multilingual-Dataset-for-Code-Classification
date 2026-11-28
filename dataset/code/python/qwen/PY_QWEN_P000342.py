s = input().strip()
res = []
for i in range(len(s)):
    if i % 2 == 0:
        res.append(s[i])
    else:
        res.append(chr(ord(s[i-1]) + int(s[i])))
print("".join(res))
