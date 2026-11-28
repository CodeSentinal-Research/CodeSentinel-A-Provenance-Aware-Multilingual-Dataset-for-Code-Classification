n = int(input())
flights = [input().split() for _ in range(n)]
budget = int(input())
for f in flights:
    if f[-2] == "Available" and int(f[-1]) <= budget:
        print(" ".join(f))
