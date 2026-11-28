
n = int(input())
records = {}
for _ in range(n):
    line = input().strip()
    eid = line.split()[0]
    records[eid] = line
query = input().strip()
print(records.get(query, "Record Not Found"))
