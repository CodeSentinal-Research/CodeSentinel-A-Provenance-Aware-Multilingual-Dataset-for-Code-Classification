
n=int(input())
products=[input().strip() for _ in range(n)]
threshold=int(input().strip())
res=[p for p in products if len(p.split())>1 and int(p.split()[-1])<threshold]
for r in res: print(r)
if not res: print('No Products Found')
