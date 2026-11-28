n, diff = map(int, input().split())
arr = list(map(int, input().split()))
s = set(arr)
found = False
for x in arr:
    if x + diff in s or x - diff in s:
        if diff == 0:
            if arr.count(x) > 1:
                found = True
                break
        else:
            found = True
            break
print("Yes" if found else "No")
