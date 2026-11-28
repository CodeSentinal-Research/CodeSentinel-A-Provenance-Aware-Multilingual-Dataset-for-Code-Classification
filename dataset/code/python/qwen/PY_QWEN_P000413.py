n = int(input())
emps = [input().split() for _ in range(n)]
dept = input().strip()
for e in emps:
    if dept in e and "Active" in e:
        print(" ".join(e))
