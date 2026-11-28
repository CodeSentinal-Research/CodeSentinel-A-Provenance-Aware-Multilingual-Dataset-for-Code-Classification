
n=int(input())
flights=[input().strip() for _ in range(n)]
budget=float(input().strip())
res=[f for f in flights if len(f.split())>0 and float(f.split()[-1])<=budget]
for r in res: print(r)
if not res: print('No Flights Found')
