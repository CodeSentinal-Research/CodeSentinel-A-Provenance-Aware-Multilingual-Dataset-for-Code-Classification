n = int(input())
prods = []
for _ in range(n):
    prods.append(input().split())
threshold = int(input())
for p in prods:
    if int(p[-1]) < threshold:
        print(" ".join(p))
