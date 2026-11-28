n = int(input())
studs = {}
for _ in range(n):
    parts = input().split()
    studs[parts[0]] = " ".join(parts[1:])
rid = input().strip()
print(studs.get(rid, "Record Not Found"))
