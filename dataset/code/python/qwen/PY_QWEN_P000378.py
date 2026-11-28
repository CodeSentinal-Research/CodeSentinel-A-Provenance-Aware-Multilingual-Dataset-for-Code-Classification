n = int(input())
flights = {}
for _ in range(n):
    parts = input().split()
    flights[parts[0]] = " ".join(parts[1:])
fid = input().strip()
print(flights.get(fid, "Flight Not Found"))
