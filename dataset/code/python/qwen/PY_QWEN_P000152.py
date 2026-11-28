n = int(input())
arr = list(map(int, input().split()))
arr.sort()
print(min(arr[0] * arr[1], arr[-1] * arr[-2]))
