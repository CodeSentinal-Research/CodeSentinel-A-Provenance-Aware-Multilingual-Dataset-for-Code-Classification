n = int(input())
arr = list(map(int, input().split()))
if n < 3:
    print(0)
else:
    left = [0] * n
    right = [0] * n
    left[0] = arr[0]
    for i in range(1, n):
        left[i] = max(left[i-1], arr[i])
    right[-1] = arr[-1]
    for i in range(n-2, -1, -1):
        right[i] = max(right[i+1], arr[i])
    ans = sum(min(left[i], right[i]) - arr[i] for i in range(n))
    print(ans)
