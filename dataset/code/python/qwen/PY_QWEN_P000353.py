n = int(input())
arr = list(map(int, input().split()))
x = int(input())
try:
    print(len(arr) - 1 - arr[::-1].index(x))
except ValueError:
    print(-1)
