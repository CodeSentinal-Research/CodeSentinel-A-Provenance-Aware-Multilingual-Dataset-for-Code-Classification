
n=int(input())
records=[input().strip() for _ in range(n)]
prefix=input().strip()
res=[r for r in records if r.split()[0].startswith(prefix)]
for r in res: print(r)
if not res: print('No Records Found')
