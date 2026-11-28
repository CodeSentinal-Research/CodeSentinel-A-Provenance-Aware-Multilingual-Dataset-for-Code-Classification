n = int(input())
arr = list(map(int, input().split()))
seen = set()
missing = -1
repeating = -1
for i in range(1, n + 1):
    if i not in arr:
        missing = i
for x in arr:
    if x in seen:
        repeating = x
    seen.add(x)
print(missing, repeating)
