n, target = map(int, input().split())
arr = list(map(int, input().split()))
seen = set()
found = False
for x in arr:
    if target - x in seen:
        found = True
        break
    seen.add(x)
if found:
    print("Yes")
else:
    print("No")
