n, target = map(int, input().split())
arr = list(map(int, input().split()))
try:
    print(arr.index(target))
except ValueError:
    print(-1)
