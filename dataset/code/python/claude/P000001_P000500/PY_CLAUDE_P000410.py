
n=int(input())
products=[input().strip() for _ in range(n)]
suffix=input().strip()
res=[p for p in products if p.split()[0].endswith(suffix)]
for r in res: print(r)
if not res: print('No Products Found')
