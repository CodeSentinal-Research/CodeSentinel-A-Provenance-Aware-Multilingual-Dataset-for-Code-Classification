n = int(input())
hotels = {}
for _ in range(n):
    parts = input().split()
    hotels[parts[0]] = " ".join(parts[1:])
hid = input().strip()
print(hotels.get(hid, "Hotel Not Found"))
