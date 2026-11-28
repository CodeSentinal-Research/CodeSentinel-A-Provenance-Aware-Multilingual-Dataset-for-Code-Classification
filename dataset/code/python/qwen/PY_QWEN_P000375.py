n = int(input())
pats = {}
for _ in range(n):
    parts = input().split()
    pats[parts[0]] = " ".join(parts[1:])
pid = input().strip()
print(pats.get(pid, "Patient Not Found"))
