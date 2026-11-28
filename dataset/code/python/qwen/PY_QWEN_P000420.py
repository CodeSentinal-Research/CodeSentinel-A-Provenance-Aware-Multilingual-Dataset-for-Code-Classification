n = int(input())
slots = [input().split() for _ in range(n)]
for s in slots:
    if s[-1] == "Available":
        print(" ".join(s))
