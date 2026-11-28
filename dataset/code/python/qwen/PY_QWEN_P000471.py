n = int(input())
arr = list(map(int, input().split()))
res = []
for i in range(n):
    count = 0
    for j in range(i + 1, n):
        if arr[j] < arr[i]:
            count += 1
    res.append(count)
print(" ".join(map(str, res)))
