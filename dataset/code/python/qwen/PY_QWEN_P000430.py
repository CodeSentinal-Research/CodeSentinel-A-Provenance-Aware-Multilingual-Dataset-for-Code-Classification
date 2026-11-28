n, target = map(int, input().split())
arr = list(map(int, input().split()))
try:
    print(len(arr) - 1 - arr[::-1].index(target))
except ValueError:
    print(-1)
