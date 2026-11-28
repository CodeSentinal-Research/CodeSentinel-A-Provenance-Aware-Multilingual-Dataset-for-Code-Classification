s = input().strip()
letters = [c for c in s if c.isalpha()]
res = []
for c in s:
    if c.isalpha():
        res.append(letters.pop())
    else:
        res.append(c)
print("".join(res))
