n = int(input())
prods = []
for _ in range(n):
    prods.append(input().split())
min_p, max_p = map(float, input().split())
for p in prods:
    if min_p <= float(p[-1]) <= max_p:
        print(" ".join(p))
