
n=int(input())
flights=[input().strip() for _ in range(n)]
dest=input().strip()
res=[f for f in flights if len(f.split())>1 and f.split()[1]==dest]
for r in res: print(r)
if not res: print('No Flights Found')
