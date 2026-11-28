
n=int(input())
records=[input().strip() for _ in range(n)]
year=int(input())
res=[r for r in records if len(r.split())>1 and int(r.split()[-1])>year]
for r in res: print(r)
if not res: print('No Records Found')
