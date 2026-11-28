
n = int(input())
products = [input().strip() for _ in range(n)]
brand = input().strip()
result = [p for p in products if len(p.split()) > 1 and p.split()[1] == brand]
if result:
    for r in result: print(r)
else:
    print("No Records Found")
