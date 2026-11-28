n = int(input())
accs = {}
for _ in range(n):
    parts = input().split()
    accs[parts[0]] = " ".join(parts[1:])
aid = input().strip()
print(accs.get(aid, "Account Not Found"))
