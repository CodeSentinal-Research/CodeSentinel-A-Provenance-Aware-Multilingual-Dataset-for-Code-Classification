p, r, t = map(float, input().split())
print(p * ((1 + r / 100) ** t) - p)
