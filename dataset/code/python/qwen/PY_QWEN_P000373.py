n = int(input())
prods = {}
for _ in range(n):
    parts = input().split()
    prods[parts[0]] = " ".join(parts[1:])
pid = input().strip()
print(prods.get(pid, "Product Not Found"))
