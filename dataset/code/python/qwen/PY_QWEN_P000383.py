n = int(input())
members = {}
for _ in range(n):
    parts = input().split()
    members[parts[0]] = " ".join(parts[1:])
mid = input().strip()
print(members.get(mid, "Member Not Found"))
