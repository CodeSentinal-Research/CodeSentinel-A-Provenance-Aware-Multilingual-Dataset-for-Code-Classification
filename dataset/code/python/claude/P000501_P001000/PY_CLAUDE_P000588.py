
n=int(input());vals=[list(map(lambda x: None if x=='null' else int(x), input().split())) for _ in range(n)]

for v in vals: print(*[str(x) if x is not None else 'null' for x in v])
