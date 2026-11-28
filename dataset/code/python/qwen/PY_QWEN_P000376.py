n = int(input())
custs = {}
for _ in range(n):
    parts = input().split()
    custs[parts[0]] = " ".join(parts[1:])
mob = input().strip()
print(custs.get(mob, "Customer Not Found"))
