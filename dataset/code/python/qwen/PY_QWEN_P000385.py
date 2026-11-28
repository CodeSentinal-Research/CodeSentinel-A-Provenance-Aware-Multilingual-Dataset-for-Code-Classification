n = int(input())
orders = {}
for _ in range(n):
    parts = input().split()
    orders[parts[0]] = " ".join(parts[1:])
oid = input().strip()
print(orders.get(oid, "Order Not Found"))
