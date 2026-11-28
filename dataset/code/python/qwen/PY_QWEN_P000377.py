n = int(input())
vehs = {}
for _ in range(n):
    parts = input().split()
    vehs[parts[0]] = " ".join(parts[1:])
reg = input().strip()
print(vehs.get(reg, "Vehicle Not Found"))
