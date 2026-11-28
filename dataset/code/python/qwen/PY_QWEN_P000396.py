n = int(input())
users = []
for _ in range(n):
    users.append(input().split())
for u in users:
    if u[-1] == "Active":
        print(" ".join(u))
