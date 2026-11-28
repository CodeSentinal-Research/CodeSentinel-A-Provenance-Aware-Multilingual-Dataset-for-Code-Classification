n = int(input())
trains = {}
for _ in range(n):
    parts = input().split()
    trains[parts[0]] = " ".join(parts[1:])
tid = input().strip()
print(trains.get(tid, "Train Not Found"))
