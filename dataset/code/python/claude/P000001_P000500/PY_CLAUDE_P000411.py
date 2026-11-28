
n=int(input())
records=[input().strip() for _ in range(n)]
kw=input().strip()
res=[r for r in records if kw in r]
for r in res: print(r)
if not res: print('No Records Found')
