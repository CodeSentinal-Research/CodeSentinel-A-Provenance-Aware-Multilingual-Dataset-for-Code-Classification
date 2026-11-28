n = int(input())
arr = list(map(int, input().split()))
d = (arr[-1] - arr[0]) // n
for i in range(1, n):
    if arr[i] - arr[i-1] != d:
        print(arr[i-1] + d)
        break
else:
    print(arr[0])
