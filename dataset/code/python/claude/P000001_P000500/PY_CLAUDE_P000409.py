
n=int(input())
users=[input().strip() for _ in range(n)]
prefix=input().strip()
res=[u for u in users if u.split()[0].startswith(prefix)]
for r in res: print(r)
if not res: print('No Users Found')
