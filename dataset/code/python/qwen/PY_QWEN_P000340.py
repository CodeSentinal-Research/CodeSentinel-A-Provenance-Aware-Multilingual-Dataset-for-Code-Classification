text = input().split()
broken = set(input().strip())
res = 0
for w in text:
    if not any(c in broken for c in w):
        res += 1
print(res)
