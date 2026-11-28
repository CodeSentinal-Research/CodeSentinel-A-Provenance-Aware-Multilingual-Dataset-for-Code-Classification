
r, c = map(int, input().split())
rows = [set(map(int, input().split())) for _ in range(r)]
common = rows[0]
for s in rows[1:]: common &= s
print(*sorted(common))
