n = int(input())
arr = list(map(int, input().split()))
arr.sort()
res = []
l, r = 0, n - 1
for i in range(n):
    if i % 2 == 0:
        res.append(arr[r])
        r -= 1
    else:
        res.append(arr[l])
        l += 1
print(" ".join(map(str, res)))
