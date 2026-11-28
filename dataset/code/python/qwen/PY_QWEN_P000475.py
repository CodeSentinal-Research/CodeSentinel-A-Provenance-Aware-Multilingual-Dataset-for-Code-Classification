target = int(input())
arr = list(map(int, input().split()))
try:
    print(arr.index(target))
except ValueError:
    print(-1)
