
n = int(input())
vehicles = [input().strip() for _ in range(n)]
manufacturer = input().strip()
result = [v for v in vehicles if len(v.split()) > 1 and v.split()[1] == manufacturer]
if result:
    for r in result: print(r)
else:
    print("No Records Found")
