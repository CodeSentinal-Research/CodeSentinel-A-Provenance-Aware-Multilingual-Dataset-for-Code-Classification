n = int(input())
rooms = []
for _ in range(n):
    rooms.append(input().split())
for r in rooms:
    if r[-1] == "Available":
        print(" ".join(r))
