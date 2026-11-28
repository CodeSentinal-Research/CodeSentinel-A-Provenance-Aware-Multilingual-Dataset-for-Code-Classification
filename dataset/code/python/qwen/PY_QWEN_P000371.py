n = int(input())
emps = {}
for _ in range(n):
    parts = input().split()
    emps[parts[0]] = " ".join(parts[1:])
eid = input().strip()
print(emps.get(eid, "Record Not Found"))
