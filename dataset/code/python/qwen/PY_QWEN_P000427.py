n = int(input())
prods = [input().split() for _ in range(n)]
min_price = float(input())
for p in prods:
    if float(p[-1]) >= min_price:
        print(" ".join(p))
