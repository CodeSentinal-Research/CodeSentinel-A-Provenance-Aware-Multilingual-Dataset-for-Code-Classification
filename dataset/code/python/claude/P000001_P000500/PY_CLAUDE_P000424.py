
n=int(input())
recs=[input().strip() for _ in range(n)]
q=input().strip()
res=[r for r in recs if len(r.split())>0 and r.split()[0]==q]
for r in res: print(r)
if not res: print('No Duplicates Found')
