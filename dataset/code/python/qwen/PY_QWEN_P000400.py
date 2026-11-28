n = int(input())
emps = []
for _ in range(n):
    emps.append(input().split())
min_s, max_s = map(float, input().split())
for e in emps:
    if min_s <= float(e[-1]) <= max_s:
        print(" ".join(e))
