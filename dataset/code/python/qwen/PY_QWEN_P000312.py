v1 = input().strip()
v2 = input().strip()
p1 = list(map(int, v1.split('.')))
p2 = list(map(int, v2.split('.')))
for i in range(max(len(p1), len(p2))):
    n1 = p1[i] if i < len(p1) else 0
    n2 = p2[i] if i < len(p2) else 0
    if n1 > n2: print(1); break
    elif n1 < n2: print(-1); break
else:
    print(0)
