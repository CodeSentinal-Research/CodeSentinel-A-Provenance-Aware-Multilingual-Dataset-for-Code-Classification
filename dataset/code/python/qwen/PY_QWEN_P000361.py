n = int(input())
arr = list(map(int, input().split()))
for i, x in enumerate(arr):
    if x % 2 != 0:
        print(i)
        break
else:
    print(-1)
