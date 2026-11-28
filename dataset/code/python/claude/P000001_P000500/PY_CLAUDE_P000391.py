
n=int(input())
records=[input().strip() for _ in range(n)]
threshold=float(input())
res=[r for r in records if float(r.split()[-1])>=threshold]
for r in res: print(r)
if not res: print('No Records Found')
