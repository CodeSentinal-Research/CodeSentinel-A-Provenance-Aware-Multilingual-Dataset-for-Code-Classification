s = input().strip()
vowels = [c for c in s if c.lower() in "aeiou"]
res = []
for c in s:
    if c.lower() in "aeiou":
        res.append(vowels.pop())
    else:
        res.append(c)
print("".join(res))
