n = int(input())
invs = {}
for _ in range(n):
    parts = input().split()
    invs[parts[0]] = " ".join(parts[1:])
iid = input().strip()
print(invs.get(iid, "Invoice Not Found"))
