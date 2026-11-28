n = int(input())
arr = list(map(int, input().split()))
counts = {}
for x in arr:
    counts[x] = counts.get(x, 0) + 1
for x, c in counts.items():
    if c > n // 2:
        print(x)
        break
