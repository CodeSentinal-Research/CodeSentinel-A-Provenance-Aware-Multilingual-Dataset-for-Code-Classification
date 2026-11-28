n = int(input())
arr = list(map(int, input().split()))
total = sum(arr)
left = 0
for i in range(n):
    if left == total - left - arr[i]:
        print(i)
        break
    left += arr[i]
else:
    print(-1)
