n = int(input())
arr = list(map(int, input().split()))
counts = {}
for x in arr:
    counts[x] = counts.get(x, 0) + 1
res = [x for x, c in counts.items() if c > n // 3]
print(" ".join(map(str, sorted(res))))
