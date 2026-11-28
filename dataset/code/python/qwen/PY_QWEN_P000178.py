n = int(input())
arr = list(map(int, input().split()))
counts = {}
for x in arr:
    counts[x] = counts.get(x, 0) + 1
arr.sort(key=lambda x: (-counts[x], x))
print(" ".join(map(str, arr)))
