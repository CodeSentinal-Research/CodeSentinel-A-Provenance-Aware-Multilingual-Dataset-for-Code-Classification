s = input().strip()
ans = 0
l_coll = 0
for c in s:
    if c == 'L':
        if l_coll > 0:
            ans += 1
            l_coll -= 1
        else:
            ans += 1
    elif c == 'R':
        l_coll += 1
    elif c == 'S':
        ans += l_coll
        l_coll = 0
print(ans + l_coll)
