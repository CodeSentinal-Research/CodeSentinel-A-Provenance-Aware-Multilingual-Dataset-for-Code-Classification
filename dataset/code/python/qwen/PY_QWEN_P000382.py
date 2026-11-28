n = int(input())
users = {}
for _ in range(n):
    parts = input().split()
    users[parts[0]] = " ".join(parts[1:])
uname = input().strip()
print(users.get(uname, "User Not Found"))
