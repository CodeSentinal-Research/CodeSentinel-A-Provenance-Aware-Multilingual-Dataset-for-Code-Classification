
n=int(input())
rooms=[input().strip() for _ in range(n)]
res=[r for r in rooms if 'available' in r.lower()]
for r in res: print(r)
if not res: print('No Records Found')
