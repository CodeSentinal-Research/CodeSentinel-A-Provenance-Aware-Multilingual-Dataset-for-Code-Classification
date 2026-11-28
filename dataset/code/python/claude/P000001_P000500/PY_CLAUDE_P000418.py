
n=int(input())
records=[input().strip() for _ in range(n)]
cutoff=input().strip()
res=[r for r in records if r.split()[-1]<cutoff]
for r in res: print(r)
if not res: print('No Employees Found')
