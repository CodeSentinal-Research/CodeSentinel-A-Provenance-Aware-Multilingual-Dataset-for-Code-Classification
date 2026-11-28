n = int(input())
trains = []
for _ in range(n):
    trains.append(input().split())
station = input().strip()
for t in trains:
    if t[-1] == station:
        print(" ".join(t))
