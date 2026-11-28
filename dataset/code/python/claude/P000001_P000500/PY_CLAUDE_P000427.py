
n=int(input())
products=[input().strip() for _ in range(n)]
min_price=float(input().strip())
res=[p for p in products if len(p.split())>1 and float(p.split()[-1])>=min_price]
for r in res: print(r)
if not res: print('No Products Found')
