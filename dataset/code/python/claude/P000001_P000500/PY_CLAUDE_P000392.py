
n=int(input())
files=[input().strip() for _ in range(n)]
ext=input().strip()
res=[f for f in files if f.endswith('.'+ext)]
for f in res: print(f)
if not res: print('No Records Found')
