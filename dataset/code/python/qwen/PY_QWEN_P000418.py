n = int(input())
emps = [input().split() for _ in range(n)]
date = input().strip()
for e in emps:
    if e[-1] < date:
        print(" ".join(e))
