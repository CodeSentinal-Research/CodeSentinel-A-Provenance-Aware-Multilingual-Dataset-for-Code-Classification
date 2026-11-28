n = int(input())
pats = [input().split() for _ in range(n)]
bg = input().strip()
for p in pats:
    if p[-1] == bg:
        print(" ".join(p))
