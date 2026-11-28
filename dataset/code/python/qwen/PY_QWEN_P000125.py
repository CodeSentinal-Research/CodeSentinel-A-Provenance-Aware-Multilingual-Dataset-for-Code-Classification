n, target = map(int, input().split())
arr = list(map(int, input().split()))
seen = {}
for i, x in enumerate(arr):
    if target - x in seen:
        print(seen[target - x], i)
        break
    seen[x] = i
