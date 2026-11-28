n = int(input())
contacts = [input().strip() for _ in range(n)]
prefix = input().strip()
for c in contacts:
    if c.startswith(prefix):
        print(c)
