n = int(input())
flights = []
for _ in range(n):
    flights.append(input().split())
dest = input().strip()
for f in flights:
    if f[-1] == dest:
        print(" ".join(f))
