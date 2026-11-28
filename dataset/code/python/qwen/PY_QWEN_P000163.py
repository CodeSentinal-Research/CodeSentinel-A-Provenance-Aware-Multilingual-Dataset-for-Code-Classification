n, target = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
found = False
for i in range(n - 2):
    l, r = i + 1, n - 1
    while l < r:
        s = arr[i] + arr[l] + arr[r]
        if s == target:
            found = True
            break
        elif s < target:
            l += 1
        else:
            r -= 1
    if found:
        break
if found:
    print("Yes")
else:
    print("No")
