# problem title : Check for Duplicate Elements
# A set records values already encountered.
n = int(input()); a = list(map(int, input().split()))[:n]
seen = set()
duplicate = False
for x in a:
    if x in seen:
        duplicate = True; break
    seen.add(x)
print("Yes" if duplicate else "No")
