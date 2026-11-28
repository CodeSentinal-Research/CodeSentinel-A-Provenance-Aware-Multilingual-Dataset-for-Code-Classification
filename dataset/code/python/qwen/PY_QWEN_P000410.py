n = int(input())
prods = [input().strip() for _ in range(n)]
suffix = input().strip()
for p in prods:
    if p.endswith(suffix):
        print(p)
