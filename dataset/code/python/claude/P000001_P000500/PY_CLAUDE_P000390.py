
n=int(input())
records=[input().strip() for _ in range(n)]
lo,hi=map(float,input().split())
res=[r for r in records if lo<=float(r.split()[1])<=hi]
for r in res: print(r)
if not res: print('No Records Found')
