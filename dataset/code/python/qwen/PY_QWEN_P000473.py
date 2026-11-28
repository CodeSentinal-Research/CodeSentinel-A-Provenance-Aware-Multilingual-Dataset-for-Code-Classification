n, target = map(int, input().split())
arr = list(map(int, input().split()))
found = -1
for i in range(n):
    if arr[i] == target:
        found = i
        break
    elif i > 0 and arr[i-1] == target:
        found = i - 1
        break
    elif i < n - 1 and arr[i+1] == target:
        found = i + 1
        break
print(found)
