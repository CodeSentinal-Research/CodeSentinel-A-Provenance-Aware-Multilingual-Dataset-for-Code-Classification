n, target = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
closest = float('inf')
for i in range(n - 2):
    l, r = i + 1, n - 1
    while l < r:
        s = arr[i] + arr[l] + arr[r]
        if abs(s - target) < abs(closest - target):
            closest = s
        if s < target:
            l += 1
        elif s > target:
            r -= 1
        else:
            break
print(closest)
