n = int(input())
devs = [input().split() for _ in range(n)]
for d in devs:
    if d[-1] == "Online":
        print(" ".join(d))
