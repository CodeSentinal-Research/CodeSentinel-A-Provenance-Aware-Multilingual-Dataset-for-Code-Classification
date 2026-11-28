n = int(input())
users = [input().strip() for _ in range(n)]
prefix = input().strip()
for u in users:
    if u.startswith(prefix):
        print(u)
