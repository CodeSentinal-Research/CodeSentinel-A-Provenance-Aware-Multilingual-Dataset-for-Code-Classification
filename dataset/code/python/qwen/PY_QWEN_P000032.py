n = int(input())
res = []
for i in range(1, int(n**0.5) + 1):
    if n % i == 0:
        res.append(i)
        if i != n // i:
            res.append(n // i)
print(" ".join(map(str, sorted(res))))
