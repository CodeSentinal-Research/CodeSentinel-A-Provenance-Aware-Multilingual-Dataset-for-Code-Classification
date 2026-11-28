n = int(input())
prods = []
for _ in range(n):
    prods.append(input().split())
brand = input().strip()
for p in prods:
    if p[-1] == brand:
        print(" ".join(p))
