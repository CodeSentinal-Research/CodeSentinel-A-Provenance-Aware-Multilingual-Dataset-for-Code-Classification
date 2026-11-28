n, target = map(int, input().split())
arr = list(map(int, input().split()))
if target in arr:
    print(arr.index(target))
else:
    print(-1)
