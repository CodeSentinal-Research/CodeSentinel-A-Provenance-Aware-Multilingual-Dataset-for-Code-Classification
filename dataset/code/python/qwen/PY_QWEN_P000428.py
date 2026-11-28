n = int(input())
events = [input().split() for _ in range(n)]
date = input().strip()
for e in events:
    if e[-1] == date:
        print(" ".join(e))
