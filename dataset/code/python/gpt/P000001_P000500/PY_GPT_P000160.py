# problem title : Find Pair with Given Sum
# A hash set makes pair-existence testing linear on average.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
seen = set(); found = False
for x in a:
    if target - x in seen:
        found = True; break
    seen.add(x)
print("Yes" if found else "No")
