
n=int(input())
users=[input().strip() for _ in range(n)]
res=[u for u in users if 'active' in u.lower()]
for u in res: print(u)
if not res: print('No Records Found')
