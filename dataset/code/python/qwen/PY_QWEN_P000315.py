s = input().strip()
res = 0
for c in s:
    res = res * 26 + (ord(c) - ord('A') + 1)
print(res)
