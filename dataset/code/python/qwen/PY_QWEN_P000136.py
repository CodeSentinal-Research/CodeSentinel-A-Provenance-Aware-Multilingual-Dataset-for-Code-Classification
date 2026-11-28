n = int(input())
arr = list(map(int, input().split()))
seen = set()
dups = []
for x in arr:
    if x in seen:
        dups.append(x)
    seen.add(x)
print(" ".join(map(str, dups)))
