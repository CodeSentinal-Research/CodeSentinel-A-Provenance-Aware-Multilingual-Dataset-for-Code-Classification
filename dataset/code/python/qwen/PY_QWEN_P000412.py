n = int(input())
contacts = [input().strip() for _ in range(n)]
name = input().strip().lower()
for c in contacts:
    if c.lower() == name:
        print(c)
