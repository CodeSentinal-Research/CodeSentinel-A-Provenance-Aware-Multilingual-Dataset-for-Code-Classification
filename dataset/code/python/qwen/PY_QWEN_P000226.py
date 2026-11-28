n = int(input())
arr = list(map(int, input().split()))
inv = 0
for i in range(n):
    for j in range(i + 1, n):
        if arr[i] > arr[j]:
            inv += 1
print(inv)
