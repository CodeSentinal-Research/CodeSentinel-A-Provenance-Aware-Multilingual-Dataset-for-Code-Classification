
n=int(input())
recs=[input().strip() for _ in range(n)]
q=input().strip()
res=[r for r in recs if len(r.split())>1 and r.split()[1]==q]
for r in res: print(r)
if not res: print('No Accounts Found')
