
n = int(input())
orders = [input().strip() for _ in range(n)]
status = input().strip()
result = [o for o in orders if len(o.split()) > 1 and o.split()[1] == status]
if result:
    for r in result: print(r)
else:
    print("No Orders Found")
