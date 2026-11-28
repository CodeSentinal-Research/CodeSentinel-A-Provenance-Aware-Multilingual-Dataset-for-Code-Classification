src = input().strip()
tgt = input().strip()
res = 0
i = 0
while i < len(tgt):
    j = 0
    found = False
    while j < len(src) and i < len(tgt):
        if src[j] == tgt[i]:
            i += 1
            found = True
        j += 1
    if not found:
        res = -1
        break
    res += 1
print(res)
