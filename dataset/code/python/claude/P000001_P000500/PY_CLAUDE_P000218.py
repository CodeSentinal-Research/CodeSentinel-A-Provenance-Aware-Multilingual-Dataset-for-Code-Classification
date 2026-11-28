
n = int(input())
a = list(map(int, input().split()))
e1, e2, c1, c2 = 0, 1, 0, 0
for x in a:
    if x == e1: c1 += 1
    elif x == e2: c2 += 1
    elif c1 == 0: e1 = x; c1 = 1
    elif c2 == 0: e2 = x; c2 = 1
    else: c1 -= 1; c2 -= 1
c1 = sum(1 for x in a if x == e1)
c2 = sum(1 for x in a if x == e2)
res = []
if c1 > n // 3: res.append(e1)
if c2 > n // 3: res.append(e2)
print(*res)
