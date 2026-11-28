n = int(input())
arr = list(map(int, input().split()))
counts = {}
for x in arr:
    counts[x] = counts.get(x, 0) + 1
for x in arr:
    if counts[x] == 1:
        print(x)
        break
else:
    print(-1)
